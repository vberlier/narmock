"""Module in charge of generating mocks."""


__all__ = ["GeneratedMock", "FileGenerator"]


import os
import re
from copy import deepcopy

from jinja2 import Environment, PackageLoader
from pycparser import c_ast as node
from pycparser.c_generator import CGenerator

from . import __version__


def decl(name, type):
    return node.Decl(name, [], [], [], type, None, None)


def function_ptr_decl(name, return_type, parameters):
    return decl(
        name, node.PtrDecl([], node.FuncDecl(node.ParamList(parameters), return_type))
    )


def void_params():
    return [decl(None, node.TypeDecl(None, [], node.IdentifierType(["void"])))]


def rename_return_type(return_type, name):
    return_type = deepcopy(return_type)
    type_decl = return_type

    while not isinstance(type_decl, node.TypeDecl):
        type_decl = type_decl.type

    type_decl.declname = name
    return return_type


def get_guard_name(filename):
    slug = re.sub(r"[^a-zA-Z0-9]", "_", os.path.normpath(os.path.relpath(filename)))
    return re.sub(r"_+", "_", slug).upper().strip("_")


def generate_includes(system_includes, local_includes, directory):
    includes = "\n".join(
        includes
        for includes in (
            "".join(f"#include <{path}>\n" for path in sorted(system_includes)),
            "".join(
                f'#include "{os.path.relpath(path, directory)}"\n'
                for path in sorted(local_includes)
            ),
        )
        if includes
    )

    return includes and f"\n{includes}"


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
        self.params_type = f"_narmock_params_type_for_{self.func_name}"

        self.func_decl = self.function.declaration.type
        self.func_params = self.func_decl.args.params if self.func_decl.args else []
        self.params_struct = [
            decl(param.name, node.PtrDecl([], param.type.type))
            if isinstance(param.type, node.ArrayDecl)
            else param
            for param in self.func_params
            if param.name
        ]
        self.forward_args = ", ".join(param.name for param in self.params_struct)

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
        self.disable_mock_decl = self.state_function("disable_mock", void_params())
        self.reset_decl = self.state_function("reset", void_params())

        self.real_decl = self.rename_function(self.real_func)
        self.wrapped_decl = self.rename_function(self.wrapped_func)

    def state_function(self, name, parameters):
        return function_ptr_decl(
            name,
            node.PtrDecl(
                [],
                node.TypeDecl(name, ["const"], node.IdentifierType([self.state_type])),
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


class FileGenerator:
    SOURCE_FILE = "__mocks__.c"
    HEADER_FILE = "__mocks__.h"

    def __init__(self):
        self.code_generator = CGenerator()

        self.jinja_env = Environment(
            loader=PackageLoader("narmock", "templates"),
            trim_blocks=True,
            lstrip_blocks=True,
        )
        self.jinja_env.filters["render"] = self.code_generator.visit

        self.source_template = self.jinja_env.get_template(f"{self.SOURCE_FILE}.jinja2")
        self.header_template = self.jinja_env.get_template(f"{self.HEADER_FILE}.jinja2")

        self.mocks = []
        self.system_includes = set()
        self.local_includes = set()

    def add_mock(self, mocked_function):
        self.mocks.append(GeneratedMock(mocked_function))

        if mocked_function.include:
            if mocked_function.include.system:
                self.system_includes.add(mocked_function.include.path)
            else:
                self.local_includes.add(mocked_function.include.path)

    def write_to_directory(self, directory):
        source_filename = os.path.join(directory, self.SOURCE_FILE)
        header_filename = os.path.join(directory, self.HEADER_FILE)

        mocks = list(sorted(self.mocks, key=lambda m: m.func_name))

        source_code = self.source_template.render(
            narmock_version=__version__,
            includes=generate_includes([], [header_filename], directory),
            mocks=mocks,
        )

        header_code = self.header_template.render(
            narmock_version=__version__,
            guard_name=get_guard_name(header_filename),
            includes=generate_includes(
                self.system_includes, self.local_includes, directory
            ),
            mocks=mocks,
        )

        with open(source_filename, "w") as source_file:
            source_file.write(source_code.strip() + "\n")

        with open(header_filename, "w") as header_file:
            header_file.write(header_code.strip() + "\n")

    @classmethod
    def read_declarations(cls, directory):
        with open(os.path.join(directory, cls.HEADER_FILE)) as header_file:
            return header_file.read()
