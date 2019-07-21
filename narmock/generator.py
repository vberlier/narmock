"""Module in charge of generating mocks."""


__all__ = ["GeneratedMock", "ImplementationFileGenerator"]


import os
import re
from copy import deepcopy
from importlib.resources import read_text

from jinja2 import Environment, PackageLoader, Template
from pycparser import c_ast as node
from pycparser.c_generator import CGenerator

from . import __version__
from .inspect import MockedFunction


JINJA_CONFIG = {"trim_blocks": True, "lstrip_blocks": True}


def decl(name, type):
    return node.Decl(name, [], [], [], type, None, None)


def function_ptr_decl(name, return_type, parameters):
    return decl(
        name, node.PtrDecl([], node.FuncDecl(node.ParamList(parameters), return_type))
    )


def rename_return_type(return_type, name):
    return_type = deepcopy(return_type)
    type_decl = return_type

    while not isinstance(type_decl, node.TypeDecl):
        type_decl = type_decl.type

    type_decl.declname = name
    return return_type


class GeneratedMock:
    DECL_MARKER = "// NARMOCK_DECLARATION"
    IMPL_MARKER = "// NARMOCK_IMPLEMENTATION"
    FLAGS_MARKER = "// NARMOCK_LINKER_FLAGS"

    FLAGS_REGEX = re.compile(fr"^{FLAGS_MARKER}\s+(.+)$", re.MULTILINE)

    @classmethod
    def extract_flags(cls, mock_declarations):
        return cls.FLAGS_REGEX.findall(mock_declarations)

    def __init__(self, function):
        self.function = function

        self.func_name = function.name

        self.wrapped_func = f"__wrap_{self.func_name}"
        self.real_func = f"__real_{self.func_name}"
        self.linker_flags = f"-Wl,--wrap={self.func_name}"

        self.state_name = f"_narmock_state_for_{self.func_name}"
        self.state_type = f"_narmock_state_type_for_{self.func_name}"
        self.private_state_type = f"_narmock_private_state_type_for_{self.func_name}"

        self.func_decl = self.function.declaration.type
        self.func_params = self.func_decl.args.params if self.func_decl.args else []
        self.forward_args = ", ".join(param.name for param in self.func_params)

        return_type = self.func_decl.type
        self.return_value = (
            None
            if isinstance(return_type, node.TypeDecl)
            and isinstance(return_type.type, node.IdentifierType)
            and return_type.type.names[0] == "void"
            else "return_value"
        )

        self.return_value_decl = decl(
            self.return_value, rename_return_type(return_type, self.return_value)
        )
        self.implementation_decl = function_ptr_decl(
            "implementation",
            rename_return_type(return_type, "implementation"),
            self.func_params,
        )

        self.mock_return_decl = self.state_function(
            "mock_return", [self.return_value_decl]
        )
        self.mock_implementation_decl = self.state_function(
            "mock_implementation", [self.implementation_decl]
        )
        self.disable_mock_decl = self.state_function(
            "disable_mock",
            [decl(None, node.TypeDecl(None, [], node.IdentifierType(["void"])))],
        )

        self.real_decl = self.rename_function(self.real_func)
        self.wrapped_decl = self.rename_function(self.wrapped_func)

    def state_function(self, name, parameters):
        return function_ptr_decl(
            name,
            node.PtrDecl(
                [], node.TypeDecl(name, [], node.IdentifierType([self.state_type]))
            ),
            parameters,
        )

    def rename_function(self, name):
        return decl(
            name,
            node.FuncDecl(
                self.func_decl.args, rename_return_type(self.func_decl.type, name)
            ),
        )


class ImplementationFileGenerator:
    DECL_BEGIN = "// NARMOCK_DECLARATIONS_BEGIN"
    DECL_END = "// NARMOCK_DECLARATIONS_END"

    @classmethod
    def extract_declarations(cls, generated_mocks, output_file):
        header_template = Template(
            read_text("narmock.templates", "__mocks__.h.jinja2"), **JINJA_CONFIG
        )

        guard_name = (
            re.sub(
                r"_+",
                "_",
                re.sub(
                    r"[^a-zA-Z0-9]", "_", os.path.normpath(os.path.relpath(output_file))
                ),
            )
            .upper()
            .strip("_")
        )

        try:
            begin = generated_mocks.index(cls.DECL_BEGIN) + len(cls.DECL_BEGIN)
            end = generated_mocks.index(cls.DECL_END)
        except ValueError:
            return

        if 0 <= begin <= end:
            extracted_header = header_template.render(
                narmock_version=__version__,
                guard_name=guard_name,
                declarations=generated_mocks[begin:end].strip(),
            )

            with open(output_file, "w") as header_file:
                header_file.write(extracted_header)

    def __init__(self):
        jinja_env = Environment(
            loader=PackageLoader("narmock", "templates"), **JINJA_CONFIG
        )
        jinja_env.filters["render"] = self.render

        self.template = jinja_env.get_template("__mocks__.c.jinja2")

        self.mocks = []
        self.system_includes = set()
        self.local_includes = set()

        self.code_generator = CGenerator()

    def add_mock(self, mocked_function):
        self.mocks.append(GeneratedMock(mocked_function))

        if mocked_function.include:
            if mocked_function.include.system:
                self.system_includes.add(mocked_function.include.path)
            else:
                self.local_includes.add(mocked_function.include.path)

    def write_to_file(self, output_file):
        directory = os.path.dirname(output_file)

        generated_code = self.template.render(
            narmock_version=__version__,
            decl_begin=self.DECL_BEGIN,
            decl_end=self.DECL_END,
            includes=self.generate_includes_relative_to(directory),
            mocks=sorted(self.mocks, key=lambda m: m.func_name),
        )

        with open(output_file, "w") as implementation_file:
            implementation_file.write(generated_code)

    def generate_includes_relative_to(self, directory):
        return "\n\n".join(
            filter(
                None,
                (
                    "\n".join(
                        f"#include <{path}>" for path in sorted(self.system_includes)
                    ),
                    "\n".join(
                        f'#include "{os.path.relpath(path, directory)}"'
                        for path in sorted(self.local_includes)
                    ),
                ),
            )
        )

    def render(self, ast_node):
        return self.code_generator.visit(ast_node)
