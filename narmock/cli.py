"""Commande-line interface."""


__all__ = ["main"]


import sys
from argparse import ArgumentParser, FileType

from .api import collect_linker_flags, generate_mocks

parser = ArgumentParser(
    prog="narmock", description="A minimal mocking utility for C projects."
)

group = parser.add_mutually_exclusive_group(required=True)
group.add_argument(
    "-g",
    metavar="<code>",
    nargs="?",
    type=FileType("r"),
    const=sys.stdin,
    help="generate mocks",
)
group.add_argument("-f", action="store_true", help="output linker flags")

parser.add_argument("-d", metavar="<directory>", default=".", help="mocks directory")

parser.add_argument(
    "-k",
    metavar="<regex>",
    nargs="?",
    default="",
    const=".*",
    help="keep argument names",
)

parser.add_argument(
    "-s",
    metavar="<size>",
    default=512,
    help="stack size used to forward variadic arguments",
)


def main():
    args = parser.parse_args()

    if args.g:
        generate_mocks(
            expanded_code=args.g.read(),
            directory=args.d,
            keep_args=args.k,
            variadic_forward_size=args.s,
        )
    elif args.f:
        print(" ".join(collect_linker_flags(directory=args.d)).strip())
