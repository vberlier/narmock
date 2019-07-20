"""Module in charge of detecting mock usage in expanded source code."""


__all__ = [
    "collect_mocked_functions",
    "IncludeDirective",
    "MockedFunction",
    "Token",
    "ForgivingDeclarationParser",
]


import os
import sys
import re
from collections import defaultdict
from typing import NamedTuple, Optional, Dict, Set, Tuple

from pycparser import c_ast as node
from pycparser.c_parser import CParser
from pycparser.plyparser import ParseError


def collect_mocked_functions(expanded_source_code, getter_prefixes):
    """Yield all the mocked functions used in the expanded source code."""

    regex = (
        r"(_narmock_state_type_[A-Za-z0-9_]+\s*\*\s*)?\b((?:"
        + "|".join(getter_prefixes)
        + r")([A-Za-z0-9_]+))\s*\(\s*\)"
    )

    getters = defaultdict(set)

    for match in re.finditer(regex, expanded_source_code):
        return_type, getter, function_name = match.groups()
        if not return_type:
            getters[function_name].add(getter)

    yield from ForgivingDeclarationParser(expanded_source_code, getters)

    if getters:
        for function in getters:
            print("error:", f"'{function}' undeclared", file=sys.stderr)
        sys.exit(1)


def rename_arguments(function_declaration):
    for i, param in enumerate(function_declaration.type.args.params):
        param.name = f"arg{i + 1}"
        param_type = param.type
        while not isinstance(param_type, node.TypeDecl):
            param_type = param_type.type
        param_type.declname = param.name
    return function_declaration


class IncludeDirective(NamedTuple):
    path: str
    system: bool

    @classmethod
    def from_source_context(cls, source_context):
        if not source_context:
            return None

        for filename in source_context:
            if not os.path.isabs(filename):
                continue

            dirname, basename = os.path.split(filename)
            fullname = basename

            while True:
                dirname, basename = os.path.split(dirname)

                if "include" in basename.lower():
                    return cls(fullname, True)

                if not basename:
                    break

                fullname = os.path.join(basename, fullname)

        return cls(os.path.abspath(source_context[-1]), False)

    def __str__(self):
        return "#include " + (f"<{self.path}>" if self.system else f'"{self.path}"')


class MockedFunction(NamedTuple):
    name: str
    declaration: str
    include: IncludeDirective
    getters: Set[str]


class Token(NamedTuple):
    type: str
    value: str
    span: Tuple[int, int]

    def is_punctuation(self, *symbols):
        return self.type == "PUNCTUATION" and self.value in symbols

    def is_keyword(self, *keywords):
        return self.type == "KEYWORD" and self.value in keywords

    @property
    def is_prefix(self):
        return self.type == "KEYWORD" and self.value in (
            "typedef",
            "extern",
            "static",
            "auto",
            "register",
            "__extension__",
        )


class ForgivingDeclarationParser:
    linemarker = re.compile(r'^# \d+ "((?:\\.|[^\\"])*)"((?: [1234])*)$')

    tokens = {
        "LINEMARKER": r"^#.*$",
        "KEYWORD": (
            "\\b(?:auto|break|case|char|const|continue|default|do|double|else|enum|extern|float"
            "|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch"
            "|typedef|union|unsigned|void|volatile|while|__extension__)\\b"
        ),
        "IDENTIFIER": r"\b[a-zA-Z_](?:[a-zA-Z_0-9])*\b",
        "CHARACTER": r"L?'(?:\\.|[^\\'])+'",
        "STRING": r'L?"(?:\\.|[^\\"])*"',
        "INTEGER": r"(?:0[xX][a-fA-F0-9]+|[0-9]+)[uUlL]*",
        "FLOAT": (
            r"(?:[0-9]+[Ee][+-]?[0-9]+|[0-9]*\.[0-9]+(?:[Ee][+-]?[0-9]+)?|[0-9]+\.[0-9]*(?:[Ee][+-]?[0-9]+)?)[fFlL]?"
        ),
        "PUNCTUATION": (
            r"\.\.\.|>>=|<<=|\+=|-=|\*=|/=|%=|&=|\^=|\|=|>>|<<|\+\+|--|->|&&|\|\||<=|>=|"
            r"==|!=|;|\{|\}|,|:|=|\(|\)|\[|\]|\.|&|!|~|-|\+|\*|/|%|<|>|\^|\||\?"
        ),
        "SPACE": r"[ \t\v\n\f]*",
        "IGNORE": r".+?",
    }

    ignored_tokens = "SPACE", "IGNORE"

    regex = re.compile(
        "|".join(f"(?P<{token}>{pattern})" for token, pattern in tokens.items()),
        flags=re.MULTILINE,
    )

    def __init__(self, source_code, getters=None):
        self.source_code = source_code
        self.getters = getters
        self.token_stream = self.tokenize(source_code)
        self.current = None

        self.bracket_stack = []
        self.source_context = []
        self.typedefs = ["typedef int __builtin_va_list;"]

        self.cparser = CParser()

    @classmethod
    def tokenize(cls, source_code):
        for match in cls.regex.finditer(source_code):
            if match.lastgroup not in cls.ignored_tokens:
                yield Token(match.lastgroup, match.group().strip(), match.span())

    def __iter__(self):
        while self.next():
            if self.current.is_keyword("typedef"):
                self.parse_typedef()

            function = self.parse_function_declaration()

            if function is not None:
                yield function

            if self.getters is not None and not self.getters:
                break

            while self.current and not (
                self.current.is_punctuation(";", "}") and not self.bracket_stack
            ):
                self.next()

    def next(self):
        self.current = next(self.token_stream, None)

        if not self.current:
            return None

        if self.current.type == "PUNCTUATION":
            if self.current.value in "({[":
                self.bracket_stack.append(")}]"["({[".index(self.current.value)])
            elif self.bracket_stack and self.current.value == self.bracket_stack[-1]:
                self.bracket_stack.pop()

        elif self.current.type == "LINEMARKER":
            filename, flags = self.linemarker.match(self.current.value).groups()

            if "1" in flags:
                self.source_context.append(filename)
            elif "2" in flags:
                self.source_context.pop()

            try:
                self.source_context[-1] = filename
            except IndexError:
                self.source_context.append(filename)

            self.next()

        return self.current

    def parse_typedef(self):
        start_index = self.current.span[0]

        while self.current and not (
            self.current.is_punctuation(";") and not self.bracket_stack
        ):
            self.next()

        self.typedefs.append(self.source_code[start_index : self.current.span[1]])

    def parse_function_declaration(self):
        if self.bracket_stack:
            return None

        while self.current and self.current.is_prefix:
            self.next()

        start_index = self.current.span[0]
        return_type = []

        while self.current and not self.current.is_punctuation("("):
            if self.current.is_punctuation(";"):
                return None

            return_type.append(self.current.value)
            self.next()

        if not return_type:
            return None

        func_name = return_type.pop()

        self.next()

        getters = set()

        if self.getters is not None:
            if func_name in self.getters:
                getters = self.getters[func_name]
            else:
                return None

        while self.current and self.bracket_stack:
            self.next()

        signature = self.source_code[start_index : self.current.span[1]] + ";"
        code = "\n".join(self.typedefs) + "\n" + signature

        try:
            file_ast = self.cparser.parse(code)
        except ParseError:
            return None
        else:
            if self.getters is not None and func_name in self.getters:
                del self.getters[func_name]

            return MockedFunction(
                func_name,
                rename_arguments(file_ast.ext[-1]),
                IncludeDirective.from_source_context(self.source_context),
                getters,
            )
