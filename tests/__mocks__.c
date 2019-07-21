/*
Mocks source file

Generated with Narmock v0.1.5 (https://github.com/vberlier/narmock)
Do not edit manually
*/

// NARMOCK_DECLARATIONS_BEGIN

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

_narmock_state_type_add *get_mock_add();
_narmock_state_type_add *other_mock_prefix_add();
_narmock_state_type_add *narmock_add();

// NARMOCK_DECLARATION compose_twice
// NARMOCK_LINKER_FLAGS -Wl,--wrap=compose_twice

typedef struct _narmock_state_type_compose_twice _narmock_state_type_compose_twice;

struct _narmock_state_type_compose_twice
{
    _narmock_state_type_compose_twice *(*mock_return)(DummyStruct *return_value);
    _narmock_state_type_compose_twice *(*mock_implementation)(DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct)));
    _narmock_state_type_compose_twice *(*disable_mock)(void);
};

_narmock_state_type_compose_twice *narmock_compose_twice();

// NARMOCK_DECLARATION edit_number
// NARMOCK_LINKER_FLAGS -Wl,--wrap=edit_number

typedef struct _narmock_state_type_edit_number _narmock_state_type_edit_number;

struct _narmock_state_type_edit_number
{
    _narmock_state_type_edit_number *(*mock_return)(DummyStruct *return_value);
    _narmock_state_type_edit_number *(*mock_implementation)(DummyStruct *(*implementation)(DummyStruct *arg1, int arg2));
    _narmock_state_type_edit_number *(*disable_mock)(void);
};

_narmock_state_type_edit_number *narmock_edit_number();

// NARMOCK_DECLARATION mount
// NARMOCK_LINKER_FLAGS -Wl,--wrap=mount

typedef struct _narmock_state_type_mount _narmock_state_type_mount;

struct _narmock_state_type_mount
{
    _narmock_state_type_mount *(*mock_return)(int return_value);
    _narmock_state_type_mount *(*mock_implementation)(int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5));
    _narmock_state_type_mount *(*disable_mock)(void);
};

_narmock_state_type_mount *narmock_mount();

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

// NARMOCK_DECLARATION return_add_one
// NARMOCK_LINKER_FLAGS -Wl,--wrap=return_add_one

typedef struct _narmock_state_type_return_add_one _narmock_state_type_return_add_one;

struct _narmock_state_type_return_add_one
{
    _narmock_state_type_return_add_one *(*mock_return)(DummyStruct *(*return_value)(DummyStruct *dummy_struct));
    _narmock_state_type_return_add_one *(*mock_implementation)(DummyStruct *(*(*implementation)())(DummyStruct *dummy_struct));
    _narmock_state_type_return_add_one *(*disable_mock)(void);
};

_narmock_state_type_return_add_one *narmock_return_add_one();

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

// NARMOCK_DECLARATIONS_END

// NARMOCK_IMPLEMENTATION add

int __real_add(int arg1, int arg2);

typedef struct _narmock_state_private_type_add _narmock_state_private_type_add;

struct _narmock_state_private_type_add
{
    _narmock_state_type_add public;

    int mode;
    int return_value;
    int (*implementation)(int arg1, int arg2);
};

_narmock_state_type_add *_narmock_function_mock_return_add(int return_value);
_narmock_state_type_add *_narmock_function_mock_implementation_add(int (*implementation)(int arg1, int arg2));
_narmock_state_type_add *_narmock_function_disable_mock_add();

_narmock_state_private_type_add _narmock_state_global_add =
{
    .public = {
        .mock_return = _narmock_function_mock_return_add,
        .mock_implementation = _narmock_function_mock_implementation_add,
        .disable_mock = _narmock_function_disable_mock_add
    },

    .mode = 0
};

int __wrap_add(int arg1, int arg2)
{
    switch (_narmock_state_global_add.mode)
    {
        case 1:
            return _narmock_state_global_add.return_value;
        case 2:
            return _narmock_state_global_add.implementation(arg1, arg2);
        default:
            return __real_add(arg1, arg2);
    }
}

_narmock_state_type_add *_narmock_function_mock_return_add(int return_value)
{
    _narmock_state_global_add.mode = 1;
    _narmock_state_global_add.return_value = return_value;

    return &_narmock_state_global_add.public;
}

_narmock_state_type_add *_narmock_function_mock_implementation_add(int (*implementation)(int arg1, int arg2))
{
    _narmock_state_global_add.mode = 2;
    _narmock_state_global_add.implementation = implementation;

    return &_narmock_state_global_add.public;
}

_narmock_state_type_add *_narmock_function_disable_mock_add()
{
    _narmock_state_global_add.mode = 0;

    return &_narmock_state_global_add.public;
}

_narmock_state_type_add *get_mock_add()
{
    return &_narmock_state_global_add.public;
}

_narmock_state_type_add *other_mock_prefix_add()
{
    return &_narmock_state_global_add.public;
}

_narmock_state_type_add *narmock_add()
{
    return &_narmock_state_global_add.public;
}

// NARMOCK_IMPLEMENTATION compose_twice

DummyStruct *__real_compose_twice(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct));

typedef struct _narmock_state_private_type_compose_twice _narmock_state_private_type_compose_twice;

struct _narmock_state_private_type_compose_twice
{
    _narmock_state_type_compose_twice public;

    int mode;
    DummyStruct *return_value;
    DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct));
};

_narmock_state_type_compose_twice *_narmock_function_mock_return_compose_twice(DummyStruct *return_value);
_narmock_state_type_compose_twice *_narmock_function_mock_implementation_compose_twice(DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct)));
_narmock_state_type_compose_twice *_narmock_function_disable_mock_compose_twice();

_narmock_state_private_type_compose_twice _narmock_state_global_compose_twice =
{
    .public = {
        .mock_return = _narmock_function_mock_return_compose_twice,
        .mock_implementation = _narmock_function_mock_implementation_compose_twice,
        .disable_mock = _narmock_function_disable_mock_compose_twice
    },

    .mode = 0
};

DummyStruct *__wrap_compose_twice(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct))
{
    switch (_narmock_state_global_compose_twice.mode)
    {
        case 1:
            return _narmock_state_global_compose_twice.return_value;
        case 2:
            return _narmock_state_global_compose_twice.implementation(arg1, arg2);
        default:
            return __real_compose_twice(arg1, arg2);
    }
}

_narmock_state_type_compose_twice *_narmock_function_mock_return_compose_twice(DummyStruct *return_value)
{
    _narmock_state_global_compose_twice.mode = 1;
    _narmock_state_global_compose_twice.return_value = return_value;

    return &_narmock_state_global_compose_twice.public;
}

_narmock_state_type_compose_twice *_narmock_function_mock_implementation_compose_twice(DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct)))
{
    _narmock_state_global_compose_twice.mode = 2;
    _narmock_state_global_compose_twice.implementation = implementation;

    return &_narmock_state_global_compose_twice.public;
}

_narmock_state_type_compose_twice *_narmock_function_disable_mock_compose_twice()
{
    _narmock_state_global_compose_twice.mode = 0;

    return &_narmock_state_global_compose_twice.public;
}

_narmock_state_type_compose_twice *narmock_compose_twice()
{
    return &_narmock_state_global_compose_twice.public;
}

// NARMOCK_IMPLEMENTATION edit_number

DummyStruct *__real_edit_number(DummyStruct *arg1, int arg2);

typedef struct _narmock_state_private_type_edit_number _narmock_state_private_type_edit_number;

struct _narmock_state_private_type_edit_number
{
    _narmock_state_type_edit_number public;

    int mode;
    DummyStruct *return_value;
    DummyStruct *(*implementation)(DummyStruct *arg1, int arg2);
};

_narmock_state_type_edit_number *_narmock_function_mock_return_edit_number(DummyStruct *return_value);
_narmock_state_type_edit_number *_narmock_function_mock_implementation_edit_number(DummyStruct *(*implementation)(DummyStruct *arg1, int arg2));
_narmock_state_type_edit_number *_narmock_function_disable_mock_edit_number();

_narmock_state_private_type_edit_number _narmock_state_global_edit_number =
{
    .public = {
        .mock_return = _narmock_function_mock_return_edit_number,
        .mock_implementation = _narmock_function_mock_implementation_edit_number,
        .disable_mock = _narmock_function_disable_mock_edit_number
    },

    .mode = 0
};

DummyStruct *__wrap_edit_number(DummyStruct *arg1, int arg2)
{
    switch (_narmock_state_global_edit_number.mode)
    {
        case 1:
            return _narmock_state_global_edit_number.return_value;
        case 2:
            return _narmock_state_global_edit_number.implementation(arg1, arg2);
        default:
            return __real_edit_number(arg1, arg2);
    }
}

_narmock_state_type_edit_number *_narmock_function_mock_return_edit_number(DummyStruct *return_value)
{
    _narmock_state_global_edit_number.mode = 1;
    _narmock_state_global_edit_number.return_value = return_value;

    return &_narmock_state_global_edit_number.public;
}

_narmock_state_type_edit_number *_narmock_function_mock_implementation_edit_number(DummyStruct *(*implementation)(DummyStruct *arg1, int arg2))
{
    _narmock_state_global_edit_number.mode = 2;
    _narmock_state_global_edit_number.implementation = implementation;

    return &_narmock_state_global_edit_number.public;
}

_narmock_state_type_edit_number *_narmock_function_disable_mock_edit_number()
{
    _narmock_state_global_edit_number.mode = 0;

    return &_narmock_state_global_edit_number.public;
}

_narmock_state_type_edit_number *narmock_edit_number()
{
    return &_narmock_state_global_edit_number.public;
}

// NARMOCK_IMPLEMENTATION mount

int __real_mount(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5);

typedef struct _narmock_state_private_type_mount _narmock_state_private_type_mount;

struct _narmock_state_private_type_mount
{
    _narmock_state_type_mount public;

    int mode;
    int return_value;
    int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5);
};

_narmock_state_type_mount *_narmock_function_mock_return_mount(int return_value);
_narmock_state_type_mount *_narmock_function_mock_implementation_mount(int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5));
_narmock_state_type_mount *_narmock_function_disable_mock_mount();

_narmock_state_private_type_mount _narmock_state_global_mount =
{
    .public = {
        .mock_return = _narmock_function_mock_return_mount,
        .mock_implementation = _narmock_function_mock_implementation_mount,
        .disable_mock = _narmock_function_disable_mock_mount
    },

    .mode = 0
};

int __wrap_mount(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5)
{
    switch (_narmock_state_global_mount.mode)
    {
        case 1:
            return _narmock_state_global_mount.return_value;
        case 2:
            return _narmock_state_global_mount.implementation(arg1, arg2, arg3, arg4, arg5);
        default:
            return __real_mount(arg1, arg2, arg3, arg4, arg5);
    }
}

_narmock_state_type_mount *_narmock_function_mock_return_mount(int return_value)
{
    _narmock_state_global_mount.mode = 1;
    _narmock_state_global_mount.return_value = return_value;

    return &_narmock_state_global_mount.public;
}

_narmock_state_type_mount *_narmock_function_mock_implementation_mount(int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5))
{
    _narmock_state_global_mount.mode = 2;
    _narmock_state_global_mount.implementation = implementation;

    return &_narmock_state_global_mount.public;
}

_narmock_state_type_mount *_narmock_function_disable_mock_mount()
{
    _narmock_state_global_mount.mode = 0;

    return &_narmock_state_global_mount.public;
}

_narmock_state_type_mount *narmock_mount()
{
    return &_narmock_state_global_mount.public;
}

// NARMOCK_IMPLEMENTATION output_message

void __real_output_message(char *arg1);

typedef struct _narmock_state_private_type_output_message _narmock_state_private_type_output_message;

struct _narmock_state_private_type_output_message
{
    _narmock_state_type_output_message public;

    int mode;
    void (*implementation)(char *arg1);
};

_narmock_state_type_output_message *_narmock_function_mock_return_output_message();
_narmock_state_type_output_message *_narmock_function_mock_implementation_output_message(void (*implementation)(char *arg1));
_narmock_state_type_output_message *_narmock_function_disable_mock_output_message();

_narmock_state_private_type_output_message _narmock_state_global_output_message =
{
    .public = {
        .mock_return = _narmock_function_mock_return_output_message,
        .mock_implementation = _narmock_function_mock_implementation_output_message,
        .disable_mock = _narmock_function_disable_mock_output_message
    },

    .mode = 0
};

void __wrap_output_message(char *arg1)
{
    switch (_narmock_state_global_output_message.mode)
    {
        case 1:
            return;
        case 2:
            return _narmock_state_global_output_message.implementation(arg1);
        default:
            return __real_output_message(arg1);
    }
}

_narmock_state_type_output_message *_narmock_function_mock_return_output_message()
{
    _narmock_state_global_output_message.mode = 1;

    return &_narmock_state_global_output_message.public;
}

_narmock_state_type_output_message *_narmock_function_mock_implementation_output_message(void (*implementation)(char *arg1))
{
    _narmock_state_global_output_message.mode = 2;
    _narmock_state_global_output_message.implementation = implementation;

    return &_narmock_state_global_output_message.public;
}

_narmock_state_type_output_message *_narmock_function_disable_mock_output_message()
{
    _narmock_state_global_output_message.mode = 0;

    return &_narmock_state_global_output_message.public;
}

_narmock_state_type_output_message *narmock_output_message()
{
    return &_narmock_state_global_output_message.public;
}

// NARMOCK_IMPLEMENTATION pipe

int __real_pipe(int arg1[2]);

typedef struct _narmock_state_private_type_pipe _narmock_state_private_type_pipe;

struct _narmock_state_private_type_pipe
{
    _narmock_state_type_pipe public;

    int mode;
    int return_value;
    int (*implementation)(int arg1[2]);
};

_narmock_state_type_pipe *_narmock_function_mock_return_pipe(int return_value);
_narmock_state_type_pipe *_narmock_function_mock_implementation_pipe(int (*implementation)(int arg1[2]));
_narmock_state_type_pipe *_narmock_function_disable_mock_pipe();

_narmock_state_private_type_pipe _narmock_state_global_pipe =
{
    .public = {
        .mock_return = _narmock_function_mock_return_pipe,
        .mock_implementation = _narmock_function_mock_implementation_pipe,
        .disable_mock = _narmock_function_disable_mock_pipe
    },

    .mode = 0
};

int __wrap_pipe(int arg1[2])
{
    switch (_narmock_state_global_pipe.mode)
    {
        case 1:
            return _narmock_state_global_pipe.return_value;
        case 2:
            return _narmock_state_global_pipe.implementation(arg1);
        default:
            return __real_pipe(arg1);
    }
}

_narmock_state_type_pipe *_narmock_function_mock_return_pipe(int return_value)
{
    _narmock_state_global_pipe.mode = 1;
    _narmock_state_global_pipe.return_value = return_value;

    return &_narmock_state_global_pipe.public;
}

_narmock_state_type_pipe *_narmock_function_mock_implementation_pipe(int (*implementation)(int arg1[2]))
{
    _narmock_state_global_pipe.mode = 2;
    _narmock_state_global_pipe.implementation = implementation;

    return &_narmock_state_global_pipe.public;
}

_narmock_state_type_pipe *_narmock_function_disable_mock_pipe()
{
    _narmock_state_global_pipe.mode = 0;

    return &_narmock_state_global_pipe.public;
}

_narmock_state_type_pipe *narmock_pipe()
{
    return &_narmock_state_global_pipe.public;
}

// NARMOCK_IMPLEMENTATION return_add_one

DummyStruct *(*__real_return_add_one())(DummyStruct *dummy_struct);

typedef struct _narmock_state_private_type_return_add_one _narmock_state_private_type_return_add_one;

struct _narmock_state_private_type_return_add_one
{
    _narmock_state_type_return_add_one public;

    int mode;
    DummyStruct *(*return_value)(DummyStruct *dummy_struct);
    DummyStruct *(*(*implementation)())(DummyStruct *dummy_struct);
};

_narmock_state_type_return_add_one *_narmock_function_mock_return_return_add_one(DummyStruct *(*return_value)(DummyStruct *dummy_struct));
_narmock_state_type_return_add_one *_narmock_function_mock_implementation_return_add_one(DummyStruct *(*(*implementation)())(DummyStruct *dummy_struct));
_narmock_state_type_return_add_one *_narmock_function_disable_mock_return_add_one();

_narmock_state_private_type_return_add_one _narmock_state_global_return_add_one =
{
    .public = {
        .mock_return = _narmock_function_mock_return_return_add_one,
        .mock_implementation = _narmock_function_mock_implementation_return_add_one,
        .disable_mock = _narmock_function_disable_mock_return_add_one
    },

    .mode = 0
};

DummyStruct *(*__wrap_return_add_one())(DummyStruct *dummy_struct)
{
    switch (_narmock_state_global_return_add_one.mode)
    {
        case 1:
            return _narmock_state_global_return_add_one.return_value;
        case 2:
            return _narmock_state_global_return_add_one.implementation();
        default:
            return __real_return_add_one();
    }
}

_narmock_state_type_return_add_one *_narmock_function_mock_return_return_add_one(DummyStruct *(*return_value)(DummyStruct *dummy_struct))
{
    _narmock_state_global_return_add_one.mode = 1;
    _narmock_state_global_return_add_one.return_value = return_value;

    return &_narmock_state_global_return_add_one.public;
}

_narmock_state_type_return_add_one *_narmock_function_mock_implementation_return_add_one(DummyStruct *(*(*implementation)())(DummyStruct *dummy_struct))
{
    _narmock_state_global_return_add_one.mode = 2;
    _narmock_state_global_return_add_one.implementation = implementation;

    return &_narmock_state_global_return_add_one.public;
}

_narmock_state_type_return_add_one *_narmock_function_disable_mock_return_add_one()
{
    _narmock_state_global_return_add_one.mode = 0;

    return &_narmock_state_global_return_add_one.public;
}

_narmock_state_type_return_add_one *narmock_return_add_one()
{
    return &_narmock_state_global_return_add_one.public;
}

// NARMOCK_IMPLEMENTATION time

time_t __real_time(time_t *arg1);

typedef struct _narmock_state_private_type_time _narmock_state_private_type_time;

struct _narmock_state_private_type_time
{
    _narmock_state_type_time public;

    int mode;
    time_t return_value;
    time_t (*implementation)(time_t *arg1);
};

_narmock_state_type_time *_narmock_function_mock_return_time(time_t return_value);
_narmock_state_type_time *_narmock_function_mock_implementation_time(time_t (*implementation)(time_t *arg1));
_narmock_state_type_time *_narmock_function_disable_mock_time();

_narmock_state_private_type_time _narmock_state_global_time =
{
    .public = {
        .mock_return = _narmock_function_mock_return_time,
        .mock_implementation = _narmock_function_mock_implementation_time,
        .disable_mock = _narmock_function_disable_mock_time
    },

    .mode = 0
};

time_t __wrap_time(time_t *arg1)
{
    switch (_narmock_state_global_time.mode)
    {
        case 1:
            return _narmock_state_global_time.return_value;
        case 2:
            return _narmock_state_global_time.implementation(arg1);
        default:
            return __real_time(arg1);
    }
}

_narmock_state_type_time *_narmock_function_mock_return_time(time_t return_value)
{
    _narmock_state_global_time.mode = 1;
    _narmock_state_global_time.return_value = return_value;

    return &_narmock_state_global_time.public;
}

_narmock_state_type_time *_narmock_function_mock_implementation_time(time_t (*implementation)(time_t *arg1))
{
    _narmock_state_global_time.mode = 2;
    _narmock_state_global_time.implementation = implementation;

    return &_narmock_state_global_time.public;
}

_narmock_state_type_time *_narmock_function_disable_mock_time()
{
    _narmock_state_global_time.mode = 0;

    return &_narmock_state_global_time.public;
}

_narmock_state_type_time *narmock_time()
{
    return &_narmock_state_global_time.public;
}
