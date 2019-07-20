"""Commande-line interface."""


__all__ = ["main"]


import sys
from argparse import ArgumentParser, FileType

from .api import generate_mocks, extract_declarations, collect_linker_flags


parser = ArgumentParser(
    prog="narmock", description="A minimal mocking utility for C projects."
)

group = parser.add_mutually_exclusive_group(required=True)
group.add_argument("-g", metavar="<file>", help="generate mocks")
group.add_argument("-d", metavar="<file>", help="extract declarations")
group.add_argument("-f", action="store_true", help="output linker flags")

parser.add_argument("-p", metavar="<string>", action="append", help="getter prefix")
parser.add_argument(
    "file",
    metavar="<file>",
    nargs="?",
    type=FileType("r"),
    default=sys.stdin,
    help="expanded code or generated mocks",
)


def main():
    args = parser.parse_args()

    if args.g:
        generate_mocks(
            expanded_code=args.file.read(),
            output_file=args.g,
            getter_prefixes=["narmock_"] + (args.p or []),
        )
    elif args.d:
        extract_declarations(generated_mocks=args.file.read(), output_file=args.d)
    elif args.f:
        print(
            " ".join(collect_linker_flags(mock_declarations=args.file.read())).strip()
        )
