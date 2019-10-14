# 🎣 narmock

[![Build Status](https://travis-ci.com/vberlier/narmock.svg?branch=master)](https://travis-ci.com/vberlier/narmock)
[![PyPI](https://img.shields.io/pypi/v/narmock.svg)](https://pypi.org/project/narmock/)
[![PyPI - Python Version](https://img.shields.io/pypi/pyversions/narmock.svg)](https://pypi.org/project/narmock/)
[![Code style: black](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/ambv/black)

> A minimal mocking utility for C projects.

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
usage: narmock [-h] (-g [<code>] | -f) [-d <directory>] [-k [<regex>]]

A minimal mocking utility for C projects.

optional arguments:
  -h, --help      show this help message and exit
  -g [<code>]     generate mocks
  -f              output linker flags
  -d <directory>  mocks directory
  -k [<regex>]    keep argument names
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

### Mocking the returned value

You can make a function return a specific value without calling its original implementation.

```c
MOCK(time)->mock_return(42);

printf("%ld\n", time(NULL));  // Outputs 42
```

### Mocking the implementation

You can switch the implementation of a function.

```c
time_t time_stub(time_t *timer)
{
    return 42;
}

MOCK(time)->mock_implementation(time_stub);

printf("%ld\n", time(NULL));  // Outputs 42
```

### Mocking errno

You can make a function set `errno` to a specific value.

```c
MOCK(malloc)->mock_return(NULL)->mock_errno(ENOMEM);

char *ptr = malloc(42);

printf("%d\n", errno == ENOMEM);  // Outputs 1
```

### Disabling the mock

You can disable the mock and make the function call its original implementation.

```c
MOCK(time)->disable_mock();

printf("%ld\n", time(NULL));  // Outputs the current time
```

### Counting and inspecting calls

Narmock keeps track of the number of times mocked functions are called.

```c
printf("%ld\n", time(NULL));  // Outputs the current time

printf("%ld\n", MOCK(time)->call_count);  // Outputs 1
```

You can also inspect the last call of a function. Note that the `last_call` pointer is `NULL` until the function gets called for the first time.

```c
printf("%ld\n", time(NULL));  // Outputs the current time

printf("%p\n", MOCK(time)->last_call->arg1);           // Outputs (nil)
printf("%ld\n", MOCK(time)->last_call->return_value);  // Outputs the current time
```

The value of `errno` is captured and saved in the `errsv` attribute.

```c
fopen("does_not_exist.txt", "r");

printf("%d\n", MOCK(fopen)->last_call->errsv == ENOENT);  // Outputs 1
```

By default, the arguments are accessible through the sequential `arg1`, `arg2`, `...`, `argN` attributes. If you want to keep the original name of the arguments for a set of specific functions you can use the `-k` option when generating the mocks.

```bash
$ gcc -E *.c | narmock -g -k "myprefix_.*"
```

The option takes a regular expression and generates mocks that use the original argument names for all the functions that match the regex.

```bash
$ gcc -E *.c | narmock -g -k
```

Note that the default regex is `.*` so here every function would be affected.

### Resetting everything

You can reset the mock to its initial state. This will make the function use its original implementation and reset `call_count` to `0` and `last_call` to `NULL`.

```c
MOCK(time)->mock_return(42);

printf("%ld\n", time(NULL));  // Outputs 42

MOCK(time)->reset();

printf("%ld\n", MOCK(time)->call_count);  // Outputs 0
printf("%p\n", MOCK(time)->last_call);    // Outputs (nil)
printf("%ld\n", time(NULL));              // Outputs the current time
```

You can also call the `narmock_reset_all_mocks` function to reset all the mock.

```c
narmock_reset_all_mocks();
```

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
