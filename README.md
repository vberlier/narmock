# narmock

[![Build Status](https://travis-ci.com/vberlier/narmock.svg?branch=master)](https://travis-ci.com/vberlier/narmock)
[![PyPI](https://img.shields.io/pypi/v/narmock.svg)](https://pypi.org/project/narmock/)
[![PyPI - Python Version](https://img.shields.io/pypi/pyversions/narmock.svg)](https://pypi.org/project/narmock/)
[![Code style: black](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/ambv/black)

> A minimal mocking utility for C projects.

🚧 Work in progress 🚧

## Contributing

Contributions are welcome. Feel free to open issues and suggest improvements. This project uses [poetry](https://poetry.eustace.io/) so you'll need to install it first if you want to be able to work with the project locally.

```bash
$ curl -sSL https://raw.githubusercontent.com/sdispater/poetry/master/get-poetry.py | python
```

You should now be able to install the required dependencies.

```bash
$ poetry install
```

The code follows the [black](https://github.com/ambv/black) code style.

```bash
$ poetry run black narmock
```

You can run the tests with `poetry run make -C tests`. The test suite is built with [Narwhal](https://github.com/vberlier/narwhal).

```bash
$ poetry run make -C tests
```
