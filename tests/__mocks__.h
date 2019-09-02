/*
Mocks header file

Generated with Narmock v0.2.3 (https://github.com/vberlier/narmock)
Do not edit manually
*/

#ifndef MOCKS_H
#define MOCKS_H

#ifndef MOCK
#define MOCK(function) (_narmock_get_mock_for_##function((void *)&function))
#endif

#include <stddef.h>
#include <sys/mount.h>
#include <time.h>
#include <unistd.h>

#include "dummy_functions.h"

// NARMOCK_DECLARATION add
// NARMOCK_LINKER_FLAGS -Wl,--wrap=add

typedef struct _narmock_state_type_for_add _narmock_state_type_for_add;
typedef struct _narmock_params_type_for_add _narmock_params_type_for_add;

struct _narmock_state_type_for_add
{
    const _narmock_state_type_for_add *(*mock_return)(int return_value);
    const _narmock_state_type_for_add *(*mock_implementation)(int (*implementation)(int arg1, int arg2));
    const _narmock_state_type_for_add *(*disable_mock)(void);
    const _narmock_state_type_for_add *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_add *last_call;
};

struct _narmock_params_type_for_add
{
    int arg1;
    int arg2;
    int return_value;
};

const _narmock_state_type_for_add *_narmock_get_mock_for_add(const void *function);

// NARMOCK_DECLARATION add_one
// NARMOCK_LINKER_FLAGS -Wl,--wrap=add_one

typedef struct _narmock_state_type_for_add_one _narmock_state_type_for_add_one;
typedef struct _narmock_params_type_for_add_one _narmock_params_type_for_add_one;

struct _narmock_state_type_for_add_one
{
    const _narmock_state_type_for_add_one *(*mock_return)(DummyStruct *return_value);
    const _narmock_state_type_for_add_one *(*mock_implementation)(DummyStruct *(*implementation)(DummyStruct *arg1));
    const _narmock_state_type_for_add_one *(*disable_mock)(void);
    const _narmock_state_type_for_add_one *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_add_one *last_call;
};

struct _narmock_params_type_for_add_one
{
    DummyStruct *arg1;
    DummyStruct *return_value;
};

const _narmock_state_type_for_add_one *_narmock_get_mock_for_add_one(const void *function);

// NARMOCK_DECLARATION compose_twice
// NARMOCK_LINKER_FLAGS -Wl,--wrap=compose_twice

typedef struct _narmock_state_type_for_compose_twice _narmock_state_type_for_compose_twice;
typedef struct _narmock_params_type_for_compose_twice _narmock_params_type_for_compose_twice;

struct _narmock_state_type_for_compose_twice
{
    const _narmock_state_type_for_compose_twice *(*mock_return)(DummyStruct *return_value);
    const _narmock_state_type_for_compose_twice *(*mock_implementation)(DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct)));
    const _narmock_state_type_for_compose_twice *(*disable_mock)(void);
    const _narmock_state_type_for_compose_twice *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_compose_twice *last_call;
};

struct _narmock_params_type_for_compose_twice
{
    DummyStruct *arg1;
    DummyStruct *(*arg2)(DummyStruct *dummy_struct);
    DummyStruct *return_value;
};

const _narmock_state_type_for_compose_twice *_narmock_get_mock_for_compose_twice(const void *function);

// NARMOCK_DECLARATION edit_number
// NARMOCK_LINKER_FLAGS -Wl,--wrap=edit_number

typedef struct _narmock_state_type_for_edit_number _narmock_state_type_for_edit_number;
typedef struct _narmock_params_type_for_edit_number _narmock_params_type_for_edit_number;

struct _narmock_state_type_for_edit_number
{
    const _narmock_state_type_for_edit_number *(*mock_return)(DummyStruct *return_value);
    const _narmock_state_type_for_edit_number *(*mock_implementation)(DummyStruct *(*implementation)(DummyStruct *arg1, int arg2));
    const _narmock_state_type_for_edit_number *(*disable_mock)(void);
    const _narmock_state_type_for_edit_number *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_edit_number *last_call;
};

struct _narmock_params_type_for_edit_number
{
    DummyStruct *arg1;
    int arg2;
    DummyStruct *return_value;
};

const _narmock_state_type_for_edit_number *_narmock_get_mock_for_edit_number(const void *function);

// NARMOCK_DECLARATION mount
// NARMOCK_LINKER_FLAGS -Wl,--wrap=mount

typedef struct _narmock_state_type_for_mount _narmock_state_type_for_mount;
typedef struct _narmock_params_type_for_mount _narmock_params_type_for_mount;

struct _narmock_state_type_for_mount
{
    const _narmock_state_type_for_mount *(*mock_return)(int return_value);
    const _narmock_state_type_for_mount *(*mock_implementation)(int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5));
    const _narmock_state_type_for_mount *(*disable_mock)(void);
    const _narmock_state_type_for_mount *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_mount *last_call;
};

struct _narmock_params_type_for_mount
{
    const char *arg1;
    const char *arg2;
    const char *arg3;
    unsigned long int arg4;
    const void *arg5;
    int return_value;
};

const _narmock_state_type_for_mount *_narmock_get_mock_for_mount(const void *function);

// NARMOCK_DECLARATION output_message
// NARMOCK_LINKER_FLAGS -Wl,--wrap=output_message

typedef struct _narmock_state_type_for_output_message _narmock_state_type_for_output_message;
typedef struct _narmock_params_type_for_output_message _narmock_params_type_for_output_message;

struct _narmock_state_type_for_output_message
{
    const _narmock_state_type_for_output_message *(*mock_return)(void);
    const _narmock_state_type_for_output_message *(*mock_implementation)(void (*implementation)(const char *arg1));
    const _narmock_state_type_for_output_message *(*disable_mock)(void);
    const _narmock_state_type_for_output_message *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_output_message *last_call;
};

struct _narmock_params_type_for_output_message
{
    const char *arg1;
};

const _narmock_state_type_for_output_message *_narmock_get_mock_for_output_message(const void *function);

// NARMOCK_DECLARATION pipe
// NARMOCK_LINKER_FLAGS -Wl,--wrap=pipe

typedef struct _narmock_state_type_for_pipe _narmock_state_type_for_pipe;
typedef struct _narmock_params_type_for_pipe _narmock_params_type_for_pipe;

struct _narmock_state_type_for_pipe
{
    const _narmock_state_type_for_pipe *(*mock_return)(int return_value);
    const _narmock_state_type_for_pipe *(*mock_implementation)(int (*implementation)(int arg1[2]));
    const _narmock_state_type_for_pipe *(*disable_mock)(void);
    const _narmock_state_type_for_pipe *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_pipe *last_call;
};

struct _narmock_params_type_for_pipe
{
    int *arg1;
    int return_value;
};

const _narmock_state_type_for_pipe *_narmock_get_mock_for_pipe(const void *function);

// NARMOCK_DECLARATION print_hello
// NARMOCK_LINKER_FLAGS -Wl,--wrap=print_hello

typedef struct _narmock_state_type_for_print_hello _narmock_state_type_for_print_hello;
typedef struct _narmock_params_type_for_print_hello _narmock_params_type_for_print_hello;

struct _narmock_state_type_for_print_hello
{
    const _narmock_state_type_for_print_hello *(*mock_return)(void);
    const _narmock_state_type_for_print_hello *(*mock_implementation)(void (*implementation)());
    const _narmock_state_type_for_print_hello *(*disable_mock)(void);
    const _narmock_state_type_for_print_hello *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_print_hello *last_call;
};

struct _narmock_params_type_for_print_hello
{
};

const _narmock_state_type_for_print_hello *_narmock_get_mock_for_print_hello(const void *function);

// NARMOCK_DECLARATION print_world
// NARMOCK_LINKER_FLAGS -Wl,--wrap=print_world

typedef struct _narmock_state_type_for_print_world _narmock_state_type_for_print_world;
typedef struct _narmock_params_type_for_print_world _narmock_params_type_for_print_world;

struct _narmock_state_type_for_print_world
{
    const _narmock_state_type_for_print_world *(*mock_return)(void);
    const _narmock_state_type_for_print_world *(*mock_implementation)(void (*implementation)(void));
    const _narmock_state_type_for_print_world *(*disable_mock)(void);
    const _narmock_state_type_for_print_world *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_print_world *last_call;
};

struct _narmock_params_type_for_print_world
{
};

const _narmock_state_type_for_print_world *_narmock_get_mock_for_print_world(const void *function);

// NARMOCK_DECLARATION return_add_one
// NARMOCK_LINKER_FLAGS -Wl,--wrap=return_add_one

typedef struct _narmock_state_type_for_return_add_one _narmock_state_type_for_return_add_one;
typedef struct _narmock_params_type_for_return_add_one _narmock_params_type_for_return_add_one;

struct _narmock_state_type_for_return_add_one
{
    const _narmock_state_type_for_return_add_one *(*mock_return)(DummyStruct *(*return_value)(DummyStruct *dummy_struct));
    const _narmock_state_type_for_return_add_one *(*mock_implementation)(DummyStruct *(*(*implementation)(void))(DummyStruct *dummy_struct));
    const _narmock_state_type_for_return_add_one *(*disable_mock)(void);
    const _narmock_state_type_for_return_add_one *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_return_add_one *last_call;
};

struct _narmock_params_type_for_return_add_one
{
    DummyStruct *(*return_value)(DummyStruct *dummy_struct);
};

const _narmock_state_type_for_return_add_one *_narmock_get_mock_for_return_add_one(const void *function);

// NARMOCK_DECLARATION time
// NARMOCK_LINKER_FLAGS -Wl,--wrap=time

typedef struct _narmock_state_type_for_time _narmock_state_type_for_time;
typedef struct _narmock_params_type_for_time _narmock_params_type_for_time;

struct _narmock_state_type_for_time
{
    const _narmock_state_type_for_time *(*mock_return)(time_t return_value);
    const _narmock_state_type_for_time *(*mock_implementation)(time_t (*implementation)(time_t *arg1));
    const _narmock_state_type_for_time *(*disable_mock)(void);
    const _narmock_state_type_for_time *(*reset)(void);
    size_t call_count;
    const _narmock_params_type_for_time *last_call;
};

struct _narmock_params_type_for_time
{
    time_t *arg1;
    time_t return_value;
};

const _narmock_state_type_for_time *_narmock_get_mock_for_time(const void *function);

#endif
