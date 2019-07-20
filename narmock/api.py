"""High-level public interface."""


__all__ = ["generate_mocks", "extract_declarations", "collect_linker_flags"]


import os

from .inspect import collect_mocked_functions
from .generator import GeneratedMock, ImplementationFileGenerator


def generate_mocks(expanded_code, output_file, getter_prefixes=()):
    """Identify mock usage and generate the implementation file."""
    generator = ImplementationFileGenerator()

    for function in collect_mocked_functions(expanded_code, getter_prefixes):
        generator.add_mock(function)

    generator.write_to_file(output_file)


def extract_declarations(generated_mocks, output_file):
    """Extract mock declarations into a standalone header."""
    ImplementationFileGenerator.extract_declarations(generated_mocks, output_file)


def collect_linker_flags(mock_declarations):
    """Return the flags needed for wrapping the declared mocked functions."""
    return GeneratedMock.extract_flags(mock_declarations)
