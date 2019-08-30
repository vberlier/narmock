/*
Mocks header file

Generated with Narmock v0.2.0 (https://github.com/vberlier/narmock)
Do not edit manually
*/

#ifndef MOCKS_H
#define MOCKS_H

#ifndef MOCK
#define MOCK(function) (_narmock_get_mock_for_##function((void *)&function))
#endif

#include <sys/mount.h>
#include <time.h>
#include <unistd.h>

#include "dummy_functions.h"

// NARMOCK_DECLARATION add
// NARMOCK_LINKER_FLAGS -Wl,--wrap=add

typedef struct _narmock_state_type_for_add _narmock_state_type_for_add;

struct _narmock_state_type_for_add
{
    _narmock_state_type_for_add *(*mock_return)(int return_value);
    _narmock_state_type_for_add *(*mock_implementation)(int (*implementation)(int arg1, int arg2));
    _narmock_state_type_for_add *(*disable_mock)(void);
};

_narmock_state_type_for_add *_narmock_get_mock_for_add(void *function);

// NARMOCK_DECLARATION compose_twice
// NARMOCK_LINKER_FLAGS -Wl,--wrap=compose_twice

typedef struct _narmock_state_type_for_compose_twice _narmock_state_type_for_compose_twice;

struct _narmock_state_type_for_compose_twice
{
    _narmock_state_type_for_compose_twice *(*mock_return)(DummyStruct *return_value);
    _narmock_state_type_for_compose_twice *(*mock_implementation)(DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct)));
    _narmock_state_type_for_compose_twice *(*disable_mock)(void);
};

_narmock_state_type_for_compose_twice *_narmock_get_mock_for_compose_twice(void *function);

// NARMOCK_DECLARATION edit_number
// NARMOCK_LINKER_FLAGS -Wl,--wrap=edit_number

typedef struct _narmock_state_type_for_edit_number _narmock_state_type_for_edit_number;

struct _narmock_state_type_for_edit_number
{
    _narmock_state_type_for_edit_number *(*mock_return)(DummyStruct *return_value);
    _narmock_state_type_for_edit_number *(*mock_implementation)(DummyStruct *(*implementation)(DummyStruct *arg1, int arg2));
    _narmock_state_type_for_edit_number *(*disable_mock)(void);
};

_narmock_state_type_for_edit_number *_narmock_get_mock_for_edit_number(void *function);

// NARMOCK_DECLARATION mount
// NARMOCK_LINKER_FLAGS -Wl,--wrap=mount

typedef struct _narmock_state_type_for_mount _narmock_state_type_for_mount;

struct _narmock_state_type_for_mount
{
    _narmock_state_type_for_mount *(*mock_return)(int return_value);
    _narmock_state_type_for_mount *(*mock_implementation)(int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5));
    _narmock_state_type_for_mount *(*disable_mock)(void);
};

_narmock_state_type_for_mount *_narmock_get_mock_for_mount(void *function);

// NARMOCK_DECLARATION output_message
// NARMOCK_LINKER_FLAGS -Wl,--wrap=output_message

typedef struct _narmock_state_type_for_output_message _narmock_state_type_for_output_message;

struct _narmock_state_type_for_output_message
{
    _narmock_state_type_for_output_message *(*mock_return)(void);
    _narmock_state_type_for_output_message *(*mock_implementation)(void (*implementation)(char *arg1));
    _narmock_state_type_for_output_message *(*disable_mock)(void);
};

_narmock_state_type_for_output_message *_narmock_get_mock_for_output_message(void *function);

// NARMOCK_DECLARATION pipe
// NARMOCK_LINKER_FLAGS -Wl,--wrap=pipe

typedef struct _narmock_state_type_for_pipe _narmock_state_type_for_pipe;

struct _narmock_state_type_for_pipe
{
    _narmock_state_type_for_pipe *(*mock_return)(int return_value);
    _narmock_state_type_for_pipe *(*mock_implementation)(int (*implementation)(int arg1[2]));
    _narmock_state_type_for_pipe *(*disable_mock)(void);
};

_narmock_state_type_for_pipe *_narmock_get_mock_for_pipe(void *function);

// NARMOCK_DECLARATION print_hello
// NARMOCK_LINKER_FLAGS -Wl,--wrap=print_hello

typedef struct _narmock_state_type_for_print_hello _narmock_state_type_for_print_hello;

struct _narmock_state_type_for_print_hello
{
    _narmock_state_type_for_print_hello *(*mock_return)(void);
    _narmock_state_type_for_print_hello *(*mock_implementation)(void (*implementation)());
    _narmock_state_type_for_print_hello *(*disable_mock)(void);
};

_narmock_state_type_for_print_hello *_narmock_get_mock_for_print_hello(void *function);

// NARMOCK_DECLARATION print_world
// NARMOCK_LINKER_FLAGS -Wl,--wrap=print_world

typedef struct _narmock_state_type_for_print_world _narmock_state_type_for_print_world;

struct _narmock_state_type_for_print_world
{
    _narmock_state_type_for_print_world *(*mock_return)(void);
    _narmock_state_type_for_print_world *(*mock_implementation)(void (*implementation)(void));
    _narmock_state_type_for_print_world *(*disable_mock)(void);
};

_narmock_state_type_for_print_world *_narmock_get_mock_for_print_world(void *function);

// NARMOCK_DECLARATION return_add_one
// NARMOCK_LINKER_FLAGS -Wl,--wrap=return_add_one

typedef struct _narmock_state_type_for_return_add_one _narmock_state_type_for_return_add_one;

struct _narmock_state_type_for_return_add_one
{
    _narmock_state_type_for_return_add_one *(*mock_return)(DummyStruct *(*return_value)(DummyStruct *dummy_struct));
    _narmock_state_type_for_return_add_one *(*mock_implementation)(DummyStruct *(*(*implementation)())(DummyStruct *dummy_struct));
    _narmock_state_type_for_return_add_one *(*disable_mock)(void);
};

_narmock_state_type_for_return_add_one *_narmock_get_mock_for_return_add_one(void *function);

// NARMOCK_DECLARATION time
// NARMOCK_LINKER_FLAGS -Wl,--wrap=time

typedef struct _narmock_state_type_for_time _narmock_state_type_for_time;

struct _narmock_state_type_for_time
{
    _narmock_state_type_for_time *(*mock_return)(time_t return_value);
    _narmock_state_type_for_time *(*mock_implementation)(time_t (*implementation)(time_t *arg1));
    _narmock_state_type_for_time *(*disable_mock)(void);
};

_narmock_state_type_for_time *_narmock_get_mock_for_time(void *function);

#endif
