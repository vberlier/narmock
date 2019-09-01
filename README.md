# 🎣 narmock

[![Build Status](https://travis-ci.com/vberlier/narmock.svg?branch=master)](https://travis-ci.com/vberlier/narmock)
[![PyPI](https://img.shields.io/pypi/v/narmock.svg)](https://pypi.org/project/narmock/)
[![PyPI - Python Version](https://img.shields.io/pypi/pyversions/narmock.svg)](https://pypi.org/project/narmock/)
[![Code style: black](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/ambv/black)

> A minimal mocking utility for C projects.

**🚧 Work in progress 🚧**

Narmock finds the functions mocked in your tests and generates mocks with a slick API.

```c
#include <time.h>

#include "__mocks__.h"
#include "narwhal.h"

TEST(example)
{
    MOCK(time)->mock_return(42);
    ASSERT_EQ(time(NULL), 42);
}
```

> This example is a test written with [Narwhal](https://github.com/vberlier/narwhal) but Narmock can be used with other test frameworks and anywhere in regular source code.

## Installation

The package can be installed with `pip`.

```bash
$ pip install narmock
```

## Getting started

The command-line utility provides two essential commands that should make it possible to integrate Narmock in any kind of build system.

```
usage: narmock [-h] (-g [<code>] | -f) [-d <directory>]

A minimal mocking utility for C projects.

optional arguments:
  -h, --help      show this help message and exit
  -g [<code>]     generate mocks
  -f              output linker flags
  -d <directory>  mocks directory
```

> Check out the [basic example](https://github.com/vberlier/narmock/tree/master/examples/basic) for a simple Makefile that integrates both [Narwhal](https://github.com/vberlier/narwhal) and Narmock.

### Generating mocks

The `narmock -g` command finds the functions mocked in your code and generates a `__mocks__.c` file and a `__mocks__.h` file that respectively define and declare all the required mocks.

```bash
$ gcc -E *.c | narmock -g
```

Narmock requires source code to be expanded by the preprocessor. You can directly pipe the output of `gcc -E` to the command-line utility.

By default, `__mocks__.c` and `__mocks__.h` will be created in the current directory. You can specify a different output directory with the `-d` option.

```bash
$ gcc -E tests/*.c | narmock -g -d tests
```

### Retrieving linker flags

The `narmock -f` command reads the generated `__mocks__.h` file and outputs the necessary linker flags for linking all your source files together.

```bash
$ gcc $(narmock -f) *.c
```

By default, the command looks for `__mocks__.h` in the current directory. You can specify a different directory with the `-d` option.

```bash
$ gcc $(narmock -f -d tests) tests/*.c
```

## Mock API

The `MOCK` macro returns a pointer to the mock API of a given function.

```c
MOCK(time);
```

### Mock return

You can make a function return a specific value without calling its original implementation.

```c
MOCK(time)->mock_return(42);

printf("%ld\n", time(NULL));  // Outputs 42
```

### Mock implementation

You can switch the implementation of a function.

```c
time_t time_stub(time_t *timer)
{
    return 42;
}

MOCK(time)->mock_implementation(time_stub);

printf("%ld\n", time(NULL));  // Outputs 42
```

### Disable mock

You can disable the mock and make the function call its original implementation.

```c
MOCK(time)->disable_mock();

printf("%ld\n", time(NULL));  // Outputs the current time
```

### Call history

You can inspect the last call of a function.

```c
printf("%ld\n", time(NULL));  // Outputs the current time

printf("%p\n", MOCK(time)->last_call->arg1);           // Outputs (nil)
printf("%ld\n", MOCK(time)->last_call->return_value);  // Outputs the current time
```

Note that the `last_call` pointer is `NULL` until the function gets called for the first time.

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

---

License - [MIT](https://github.com/vberlier/narmock/blob/master/LICENSE)
