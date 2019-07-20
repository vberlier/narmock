/*
Mocks header file

Generated with Narmock v0.1.4 (https://github.com/vberlier/narmock)
Do not edit manually
*/

#ifndef MOCKS_H
#define MOCKS_H

#include <sys/mount.h>
#include <time.h>
#include <unistd.h>

#include "dummy_functions.h"

// NARMOCK_DECLARATION add
// NARMOCK_LINKER_FLAGS -Wl,--wrap=add

typedef struct _narmock_state_type_add _narmock_state_type_add;

struct _narmock_state_type_add
{
    _narmock_state_type_add *(*mock_return)(int return_value);
    _narmock_state_type_add *(*mock_implementation)(int (*implementation)(int arg1, int arg2));
    _narmock_state_type_add *(*disable_mock)(void);
};

_narmock_state_type_add *other_mock_prefix_add();
_narmock_state_type_add *get_mock_add();
_narmock_state_type_add *narmock_add();

// NARMOCK_DECLARATION output_message
// NARMOCK_LINKER_FLAGS -Wl,--wrap=output_message

typedef struct _narmock_state_type_output_message _narmock_state_type_output_message;

struct _narmock_state_type_output_message
{
    _narmock_state_type_output_message *(*mock_return)(void);
    _narmock_state_type_output_message *(*mock_implementation)(void (*implementation)(char *arg1));
    _narmock_state_type_output_message *(*disable_mock)(void);
};

_narmock_state_type_output_message *narmock_output_message();

// NARMOCK_DECLARATION edit_number
// NARMOCK_LINKER_FLAGS -Wl,--wrap=edit_number

typedef struct _narmock_state_type_edit_number _narmock_state_type_edit_number;

struct _narmock_state_type_edit_number
{
    _narmock_state_type_edit_number *(*mock_return)(DummyStruct *return_value);
    _narmock_state_type_edit_number *(*mock_implementation)(
        DummyStruct *(*implementation)(DummyStruct *arg1, int arg2));
    _narmock_state_type_edit_number *(*disable_mock)(void);
};

_narmock_state_type_edit_number *narmock_edit_number();

// NARMOCK_DECLARATION compose_twice
// NARMOCK_LINKER_FLAGS -Wl,--wrap=compose_twice

typedef struct _narmock_state_type_compose_twice _narmock_state_type_compose_twice;

struct _narmock_state_type_compose_twice
{
    _narmock_state_type_compose_twice *(*mock_return)(DummyStruct *return_value);
    _narmock_state_type_compose_twice *(*mock_implementation)(DummyStruct *(
        *implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct)));
    _narmock_state_type_compose_twice *(*disable_mock)(void);
};

_narmock_state_type_compose_twice *narmock_compose_twice();

// NARMOCK_DECLARATION mount
// NARMOCK_LINKER_FLAGS -Wl,--wrap=mount

typedef struct _narmock_state_type_mount _narmock_state_type_mount;

struct _narmock_state_type_mount
{
    _narmock_state_type_mount *(*mock_return)(int return_value);
    _narmock_state_type_mount *(*mock_implementation)(int (*implementation)(const char *arg1,
                                                                            const char *arg2,
                                                                            const char *arg3,
                                                                            unsigned long int arg4,
                                                                            const void *arg5));
    _narmock_state_type_mount *(*disable_mock)(void);
};

_narmock_state_type_mount *narmock_mount();

// NARMOCK_DECLARATION time
// NARMOCK_LINKER_FLAGS -Wl,--wrap=time

typedef struct _narmock_state_type_time _narmock_state_type_time;

struct _narmock_state_type_time
{
    _narmock_state_type_time *(*mock_return)(time_t return_value);
    _narmock_state_type_time *(*mock_implementation)(time_t (*implementation)(time_t *arg1));
    _narmock_state_type_time *(*disable_mock)(void);
};

_narmock_state_type_time *narmock_time();

// NARMOCK_DECLARATION pipe
// NARMOCK_LINKER_FLAGS -Wl,--wrap=pipe

typedef struct _narmock_state_type_pipe _narmock_state_type_pipe;

struct _narmock_state_type_pipe
{
    _narmock_state_type_pipe *(*mock_return)(int return_value);
    _narmock_state_type_pipe *(*mock_implementation)(int (*implementation)(int arg1[2]));
    _narmock_state_type_pipe *(*disable_mock)(void);
};

_narmock_state_type_pipe *narmock_pipe();

#endif
