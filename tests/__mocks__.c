/*
Mocks source file

Generated with Narmock v0.2.0 (https://github.com/vberlier/narmock)
Do not edit manually
*/

#include "__mocks__.h"

// NARMOCK_IMPLEMENTATION add

int __real_add(int arg1, int arg2);

typedef struct _narmock_private_state_type_for_add _narmock_private_state_type_for_add;

struct _narmock_private_state_type_for_add
{
    _narmock_state_type_for_add public;

    int mode;
    int return_value;
    int (*implementation)(int arg1, int arg2);
    _narmock_params_type_for_add last_call;
};

_narmock_state_type_for_add *_narmock_mock_return_function_for_add(int return_value);
_narmock_state_type_for_add *_narmock_mock_implementation_function_for_add(int (*implementation)(int arg1, int arg2));
_narmock_state_type_for_add *_narmock_disable_mock_function_for_add();

_narmock_private_state_type_for_add _narmock_state_for_add =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_add,
        .mock_implementation = _narmock_mock_implementation_function_for_add,
        .disable_mock = _narmock_disable_mock_function_for_add,
        .last_call = NULL
    },

    .mode = 0
};

int __wrap_add(int arg1, int arg2)
{
    int return_value;

    switch (_narmock_state_for_add.mode)
    {
        case 1:
            return_value =
            _narmock_state_for_add.return_value;
            break;
        case 2:
            return_value =
            _narmock_state_for_add.implementation(arg1, arg2);
            break;
        default:
            return_value =
            __real_add(arg1, arg2);
            break;
    }

    _narmock_params_type_for_add last_call = { arg1, arg2, return_value };

    _narmock_state_for_add.last_call = last_call;
    _narmock_state_for_add.public.last_call = &_narmock_state_for_add.last_call;

    return return_value;
}

_narmock_state_type_for_add *_narmock_mock_return_function_for_add(int return_value)
{
    _narmock_state_for_add.mode = 1;
    _narmock_state_for_add.return_value = return_value;

    return &_narmock_state_for_add.public;
}

_narmock_state_type_for_add *_narmock_mock_implementation_function_for_add(int (*implementation)(int arg1, int arg2))
{
    _narmock_state_for_add.mode = 2;
    _narmock_state_for_add.implementation = implementation;

    return &_narmock_state_for_add.public;
}

_narmock_state_type_for_add *_narmock_disable_mock_function_for_add()
{
    _narmock_state_for_add.mode = 0;

    return &_narmock_state_for_add.public;
}

_narmock_state_type_for_add *_narmock_get_mock_for_add(const void *function)
{
    (void)function;

    return &_narmock_state_for_add.public;
}

// NARMOCK_IMPLEMENTATION add_one

DummyStruct *__real_add_one(DummyStruct *arg1);

typedef struct _narmock_private_state_type_for_add_one _narmock_private_state_type_for_add_one;

struct _narmock_private_state_type_for_add_one
{
    _narmock_state_type_for_add_one public;

    int mode;
    DummyStruct *return_value;
    DummyStruct *(*implementation)(DummyStruct *arg1);
    _narmock_params_type_for_add_one last_call;
};

_narmock_state_type_for_add_one *_narmock_mock_return_function_for_add_one(DummyStruct *return_value);
_narmock_state_type_for_add_one *_narmock_mock_implementation_function_for_add_one(DummyStruct *(*implementation)(DummyStruct *arg1));
_narmock_state_type_for_add_one *_narmock_disable_mock_function_for_add_one();

_narmock_private_state_type_for_add_one _narmock_state_for_add_one =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_add_one,
        .mock_implementation = _narmock_mock_implementation_function_for_add_one,
        .disable_mock = _narmock_disable_mock_function_for_add_one,
        .last_call = NULL
    },

    .mode = 0
};

DummyStruct *__wrap_add_one(DummyStruct *arg1)
{
    DummyStruct *return_value;

    switch (_narmock_state_for_add_one.mode)
    {
        case 1:
            return_value =
            _narmock_state_for_add_one.return_value;
            break;
        case 2:
            return_value =
            _narmock_state_for_add_one.implementation(arg1);
            break;
        default:
            return_value =
            __real_add_one(arg1);
            break;
    }

    _narmock_params_type_for_add_one last_call = { arg1, return_value };

    _narmock_state_for_add_one.last_call = last_call;
    _narmock_state_for_add_one.public.last_call = &_narmock_state_for_add_one.last_call;

    return return_value;
}

_narmock_state_type_for_add_one *_narmock_mock_return_function_for_add_one(DummyStruct *return_value)
{
    _narmock_state_for_add_one.mode = 1;
    _narmock_state_for_add_one.return_value = return_value;

    return &_narmock_state_for_add_one.public;
}

_narmock_state_type_for_add_one *_narmock_mock_implementation_function_for_add_one(DummyStruct *(*implementation)(DummyStruct *arg1))
{
    _narmock_state_for_add_one.mode = 2;
    _narmock_state_for_add_one.implementation = implementation;

    return &_narmock_state_for_add_one.public;
}

_narmock_state_type_for_add_one *_narmock_disable_mock_function_for_add_one()
{
    _narmock_state_for_add_one.mode = 0;

    return &_narmock_state_for_add_one.public;
}

_narmock_state_type_for_add_one *_narmock_get_mock_for_add_one(const void *function)
{
    (void)function;

    return &_narmock_state_for_add_one.public;
}

// NARMOCK_IMPLEMENTATION compose_twice

DummyStruct *__real_compose_twice(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct));

typedef struct _narmock_private_state_type_for_compose_twice _narmock_private_state_type_for_compose_twice;

struct _narmock_private_state_type_for_compose_twice
{
    _narmock_state_type_for_compose_twice public;

    int mode;
    DummyStruct *return_value;
    DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct));
    _narmock_params_type_for_compose_twice last_call;
};

_narmock_state_type_for_compose_twice *_narmock_mock_return_function_for_compose_twice(DummyStruct *return_value);
_narmock_state_type_for_compose_twice *_narmock_mock_implementation_function_for_compose_twice(DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct)));
_narmock_state_type_for_compose_twice *_narmock_disable_mock_function_for_compose_twice();

_narmock_private_state_type_for_compose_twice _narmock_state_for_compose_twice =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_compose_twice,
        .mock_implementation = _narmock_mock_implementation_function_for_compose_twice,
        .disable_mock = _narmock_disable_mock_function_for_compose_twice,
        .last_call = NULL
    },

    .mode = 0
};

DummyStruct *__wrap_compose_twice(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct))
{
    DummyStruct *return_value;

    switch (_narmock_state_for_compose_twice.mode)
    {
        case 1:
            return_value =
            _narmock_state_for_compose_twice.return_value;
            break;
        case 2:
            return_value =
            _narmock_state_for_compose_twice.implementation(arg1, arg2);
            break;
        default:
            return_value =
            __real_compose_twice(arg1, arg2);
            break;
    }

    _narmock_params_type_for_compose_twice last_call = { arg1, arg2, return_value };

    _narmock_state_for_compose_twice.last_call = last_call;
    _narmock_state_for_compose_twice.public.last_call = &_narmock_state_for_compose_twice.last_call;

    return return_value;
}

_narmock_state_type_for_compose_twice *_narmock_mock_return_function_for_compose_twice(DummyStruct *return_value)
{
    _narmock_state_for_compose_twice.mode = 1;
    _narmock_state_for_compose_twice.return_value = return_value;

    return &_narmock_state_for_compose_twice.public;
}

_narmock_state_type_for_compose_twice *_narmock_mock_implementation_function_for_compose_twice(DummyStruct *(*implementation)(DummyStruct *arg1, DummyStruct *(*arg2)(DummyStruct *dummy_struct)))
{
    _narmock_state_for_compose_twice.mode = 2;
    _narmock_state_for_compose_twice.implementation = implementation;

    return &_narmock_state_for_compose_twice.public;
}

_narmock_state_type_for_compose_twice *_narmock_disable_mock_function_for_compose_twice()
{
    _narmock_state_for_compose_twice.mode = 0;

    return &_narmock_state_for_compose_twice.public;
}

_narmock_state_type_for_compose_twice *_narmock_get_mock_for_compose_twice(const void *function)
{
    (void)function;

    return &_narmock_state_for_compose_twice.public;
}

// NARMOCK_IMPLEMENTATION edit_number

DummyStruct *__real_edit_number(DummyStruct *arg1, int arg2);

typedef struct _narmock_private_state_type_for_edit_number _narmock_private_state_type_for_edit_number;

struct _narmock_private_state_type_for_edit_number
{
    _narmock_state_type_for_edit_number public;

    int mode;
    DummyStruct *return_value;
    DummyStruct *(*implementation)(DummyStruct *arg1, int arg2);
    _narmock_params_type_for_edit_number last_call;
};

_narmock_state_type_for_edit_number *_narmock_mock_return_function_for_edit_number(DummyStruct *return_value);
_narmock_state_type_for_edit_number *_narmock_mock_implementation_function_for_edit_number(DummyStruct *(*implementation)(DummyStruct *arg1, int arg2));
_narmock_state_type_for_edit_number *_narmock_disable_mock_function_for_edit_number();

_narmock_private_state_type_for_edit_number _narmock_state_for_edit_number =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_edit_number,
        .mock_implementation = _narmock_mock_implementation_function_for_edit_number,
        .disable_mock = _narmock_disable_mock_function_for_edit_number,
        .last_call = NULL
    },

    .mode = 0
};

DummyStruct *__wrap_edit_number(DummyStruct *arg1, int arg2)
{
    DummyStruct *return_value;

    switch (_narmock_state_for_edit_number.mode)
    {
        case 1:
            return_value =
            _narmock_state_for_edit_number.return_value;
            break;
        case 2:
            return_value =
            _narmock_state_for_edit_number.implementation(arg1, arg2);
            break;
        default:
            return_value =
            __real_edit_number(arg1, arg2);
            break;
    }

    _narmock_params_type_for_edit_number last_call = { arg1, arg2, return_value };

    _narmock_state_for_edit_number.last_call = last_call;
    _narmock_state_for_edit_number.public.last_call = &_narmock_state_for_edit_number.last_call;

    return return_value;
}

_narmock_state_type_for_edit_number *_narmock_mock_return_function_for_edit_number(DummyStruct *return_value)
{
    _narmock_state_for_edit_number.mode = 1;
    _narmock_state_for_edit_number.return_value = return_value;

    return &_narmock_state_for_edit_number.public;
}

_narmock_state_type_for_edit_number *_narmock_mock_implementation_function_for_edit_number(DummyStruct *(*implementation)(DummyStruct *arg1, int arg2))
{
    _narmock_state_for_edit_number.mode = 2;
    _narmock_state_for_edit_number.implementation = implementation;

    return &_narmock_state_for_edit_number.public;
}

_narmock_state_type_for_edit_number *_narmock_disable_mock_function_for_edit_number()
{
    _narmock_state_for_edit_number.mode = 0;

    return &_narmock_state_for_edit_number.public;
}

_narmock_state_type_for_edit_number *_narmock_get_mock_for_edit_number(const void *function)
{
    (void)function;

    return &_narmock_state_for_edit_number.public;
}

// NARMOCK_IMPLEMENTATION mount

int __real_mount(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5);

typedef struct _narmock_private_state_type_for_mount _narmock_private_state_type_for_mount;

struct _narmock_private_state_type_for_mount
{
    _narmock_state_type_for_mount public;

    int mode;
    int return_value;
    int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5);
    _narmock_params_type_for_mount last_call;
};

_narmock_state_type_for_mount *_narmock_mock_return_function_for_mount(int return_value);
_narmock_state_type_for_mount *_narmock_mock_implementation_function_for_mount(int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5));
_narmock_state_type_for_mount *_narmock_disable_mock_function_for_mount();

_narmock_private_state_type_for_mount _narmock_state_for_mount =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_mount,
        .mock_implementation = _narmock_mock_implementation_function_for_mount,
        .disable_mock = _narmock_disable_mock_function_for_mount,
        .last_call = NULL
    },

    .mode = 0
};

int __wrap_mount(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5)
{
    int return_value;

    switch (_narmock_state_for_mount.mode)
    {
        case 1:
            return_value =
            _narmock_state_for_mount.return_value;
            break;
        case 2:
            return_value =
            _narmock_state_for_mount.implementation(arg1, arg2, arg3, arg4, arg5);
            break;
        default:
            return_value =
            __real_mount(arg1, arg2, arg3, arg4, arg5);
            break;
    }

    _narmock_params_type_for_mount last_call = { arg1, arg2, arg3, arg4, arg5, return_value };

    _narmock_state_for_mount.last_call = last_call;
    _narmock_state_for_mount.public.last_call = &_narmock_state_for_mount.last_call;

    return return_value;
}

_narmock_state_type_for_mount *_narmock_mock_return_function_for_mount(int return_value)
{
    _narmock_state_for_mount.mode = 1;
    _narmock_state_for_mount.return_value = return_value;

    return &_narmock_state_for_mount.public;
}

_narmock_state_type_for_mount *_narmock_mock_implementation_function_for_mount(int (*implementation)(const char *arg1, const char *arg2, const char *arg3, unsigned long int arg4, const void *arg5))
{
    _narmock_state_for_mount.mode = 2;
    _narmock_state_for_mount.implementation = implementation;

    return &_narmock_state_for_mount.public;
}

_narmock_state_type_for_mount *_narmock_disable_mock_function_for_mount()
{
    _narmock_state_for_mount.mode = 0;

    return &_narmock_state_for_mount.public;
}

_narmock_state_type_for_mount *_narmock_get_mock_for_mount(const void *function)
{
    (void)function;

    return &_narmock_state_for_mount.public;
}

// NARMOCK_IMPLEMENTATION output_message

void __real_output_message(const char *arg1);

typedef struct _narmock_private_state_type_for_output_message _narmock_private_state_type_for_output_message;

struct _narmock_private_state_type_for_output_message
{
    _narmock_state_type_for_output_message public;

    int mode;
    void (*implementation)(const char *arg1);
    _narmock_params_type_for_output_message last_call;
};

_narmock_state_type_for_output_message *_narmock_mock_return_function_for_output_message();
_narmock_state_type_for_output_message *_narmock_mock_implementation_function_for_output_message(void (*implementation)(const char *arg1));
_narmock_state_type_for_output_message *_narmock_disable_mock_function_for_output_message();

_narmock_private_state_type_for_output_message _narmock_state_for_output_message =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_output_message,
        .mock_implementation = _narmock_mock_implementation_function_for_output_message,
        .disable_mock = _narmock_disable_mock_function_for_output_message,
        .last_call = NULL
    },

    .mode = 0
};

void __wrap_output_message(const char *arg1)
{
    switch (_narmock_state_for_output_message.mode)
    {
        case 1:
            break;
        case 2:
            _narmock_state_for_output_message.implementation(arg1);
            break;
        default:
            __real_output_message(arg1);
            break;
    }

    _narmock_params_type_for_output_message last_call = { arg1 };

    _narmock_state_for_output_message.last_call = last_call;
    _narmock_state_for_output_message.public.last_call = &_narmock_state_for_output_message.last_call;

    return;
}

_narmock_state_type_for_output_message *_narmock_mock_return_function_for_output_message()
{
    _narmock_state_for_output_message.mode = 1;

    return &_narmock_state_for_output_message.public;
}

_narmock_state_type_for_output_message *_narmock_mock_implementation_function_for_output_message(void (*implementation)(const char *arg1))
{
    _narmock_state_for_output_message.mode = 2;
    _narmock_state_for_output_message.implementation = implementation;

    return &_narmock_state_for_output_message.public;
}

_narmock_state_type_for_output_message *_narmock_disable_mock_function_for_output_message()
{
    _narmock_state_for_output_message.mode = 0;

    return &_narmock_state_for_output_message.public;
}

_narmock_state_type_for_output_message *_narmock_get_mock_for_output_message(const void *function)
{
    (void)function;

    return &_narmock_state_for_output_message.public;
}

// NARMOCK_IMPLEMENTATION pipe

int __real_pipe(int arg1[2]);

typedef struct _narmock_private_state_type_for_pipe _narmock_private_state_type_for_pipe;

struct _narmock_private_state_type_for_pipe
{
    _narmock_state_type_for_pipe public;

    int mode;
    int return_value;
    int (*implementation)(int arg1[2]);
    _narmock_params_type_for_pipe last_call;
};

_narmock_state_type_for_pipe *_narmock_mock_return_function_for_pipe(int return_value);
_narmock_state_type_for_pipe *_narmock_mock_implementation_function_for_pipe(int (*implementation)(int arg1[2]));
_narmock_state_type_for_pipe *_narmock_disable_mock_function_for_pipe();

_narmock_private_state_type_for_pipe _narmock_state_for_pipe =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_pipe,
        .mock_implementation = _narmock_mock_implementation_function_for_pipe,
        .disable_mock = _narmock_disable_mock_function_for_pipe,
        .last_call = NULL
    },

    .mode = 0
};

int __wrap_pipe(int arg1[2])
{
    int return_value;

    switch (_narmock_state_for_pipe.mode)
    {
        case 1:
            return_value =
            _narmock_state_for_pipe.return_value;
            break;
        case 2:
            return_value =
            _narmock_state_for_pipe.implementation(arg1);
            break;
        default:
            return_value =
            __real_pipe(arg1);
            break;
    }

    _narmock_params_type_for_pipe last_call = { arg1, return_value };

    _narmock_state_for_pipe.last_call = last_call;
    _narmock_state_for_pipe.public.last_call = &_narmock_state_for_pipe.last_call;

    return return_value;
}

_narmock_state_type_for_pipe *_narmock_mock_return_function_for_pipe(int return_value)
{
    _narmock_state_for_pipe.mode = 1;
    _narmock_state_for_pipe.return_value = return_value;

    return &_narmock_state_for_pipe.public;
}

_narmock_state_type_for_pipe *_narmock_mock_implementation_function_for_pipe(int (*implementation)(int arg1[2]))
{
    _narmock_state_for_pipe.mode = 2;
    _narmock_state_for_pipe.implementation = implementation;

    return &_narmock_state_for_pipe.public;
}

_narmock_state_type_for_pipe *_narmock_disable_mock_function_for_pipe()
{
    _narmock_state_for_pipe.mode = 0;

    return &_narmock_state_for_pipe.public;
}

_narmock_state_type_for_pipe *_narmock_get_mock_for_pipe(const void *function)
{
    (void)function;

    return &_narmock_state_for_pipe.public;
}

// NARMOCK_IMPLEMENTATION print_hello

void __real_print_hello();

typedef struct _narmock_private_state_type_for_print_hello _narmock_private_state_type_for_print_hello;

struct _narmock_private_state_type_for_print_hello
{
    _narmock_state_type_for_print_hello public;

    int mode;
    void (*implementation)();
    _narmock_params_type_for_print_hello last_call;
};

_narmock_state_type_for_print_hello *_narmock_mock_return_function_for_print_hello();
_narmock_state_type_for_print_hello *_narmock_mock_implementation_function_for_print_hello(void (*implementation)());
_narmock_state_type_for_print_hello *_narmock_disable_mock_function_for_print_hello();

_narmock_private_state_type_for_print_hello _narmock_state_for_print_hello =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_print_hello,
        .mock_implementation = _narmock_mock_implementation_function_for_print_hello,
        .disable_mock = _narmock_disable_mock_function_for_print_hello,
        .last_call = NULL
    },

    .mode = 0
};

void __wrap_print_hello()
{
    switch (_narmock_state_for_print_hello.mode)
    {
        case 1:
            break;
        case 2:
            _narmock_state_for_print_hello.implementation();
            break;
        default:
            __real_print_hello();
            break;
    }

    _narmock_params_type_for_print_hello last_call = { };

    _narmock_state_for_print_hello.last_call = last_call;
    _narmock_state_for_print_hello.public.last_call = &_narmock_state_for_print_hello.last_call;

    return;
}

_narmock_state_type_for_print_hello *_narmock_mock_return_function_for_print_hello()
{
    _narmock_state_for_print_hello.mode = 1;

    return &_narmock_state_for_print_hello.public;
}

_narmock_state_type_for_print_hello *_narmock_mock_implementation_function_for_print_hello(void (*implementation)())
{
    _narmock_state_for_print_hello.mode = 2;
    _narmock_state_for_print_hello.implementation = implementation;

    return &_narmock_state_for_print_hello.public;
}

_narmock_state_type_for_print_hello *_narmock_disable_mock_function_for_print_hello()
{
    _narmock_state_for_print_hello.mode = 0;

    return &_narmock_state_for_print_hello.public;
}

_narmock_state_type_for_print_hello *_narmock_get_mock_for_print_hello(const void *function)
{
    (void)function;

    return &_narmock_state_for_print_hello.public;
}

// NARMOCK_IMPLEMENTATION print_world

void __real_print_world(void);

typedef struct _narmock_private_state_type_for_print_world _narmock_private_state_type_for_print_world;

struct _narmock_private_state_type_for_print_world
{
    _narmock_state_type_for_print_world public;

    int mode;
    void (*implementation)(void);
    _narmock_params_type_for_print_world last_call;
};

_narmock_state_type_for_print_world *_narmock_mock_return_function_for_print_world();
_narmock_state_type_for_print_world *_narmock_mock_implementation_function_for_print_world(void (*implementation)(void));
_narmock_state_type_for_print_world *_narmock_disable_mock_function_for_print_world();

_narmock_private_state_type_for_print_world _narmock_state_for_print_world =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_print_world,
        .mock_implementation = _narmock_mock_implementation_function_for_print_world,
        .disable_mock = _narmock_disable_mock_function_for_print_world,
        .last_call = NULL
    },

    .mode = 0
};

void __wrap_print_world(void)
{
    switch (_narmock_state_for_print_world.mode)
    {
        case 1:
            break;
        case 2:
            _narmock_state_for_print_world.implementation();
            break;
        default:
            __real_print_world();
            break;
    }

    _narmock_params_type_for_print_world last_call = { };

    _narmock_state_for_print_world.last_call = last_call;
    _narmock_state_for_print_world.public.last_call = &_narmock_state_for_print_world.last_call;

    return;
}

_narmock_state_type_for_print_world *_narmock_mock_return_function_for_print_world()
{
    _narmock_state_for_print_world.mode = 1;

    return &_narmock_state_for_print_world.public;
}

_narmock_state_type_for_print_world *_narmock_mock_implementation_function_for_print_world(void (*implementation)(void))
{
    _narmock_state_for_print_world.mode = 2;
    _narmock_state_for_print_world.implementation = implementation;

    return &_narmock_state_for_print_world.public;
}

_narmock_state_type_for_print_world *_narmock_disable_mock_function_for_print_world()
{
    _narmock_state_for_print_world.mode = 0;

    return &_narmock_state_for_print_world.public;
}

_narmock_state_type_for_print_world *_narmock_get_mock_for_print_world(const void *function)
{
    (void)function;

    return &_narmock_state_for_print_world.public;
}

// NARMOCK_IMPLEMENTATION return_add_one

DummyStruct *(*__real_return_add_one())(DummyStruct *dummy_struct);

typedef struct _narmock_private_state_type_for_return_add_one _narmock_private_state_type_for_return_add_one;

struct _narmock_private_state_type_for_return_add_one
{
    _narmock_state_type_for_return_add_one public;

    int mode;
    DummyStruct *(*return_value)(DummyStruct *dummy_struct);
    DummyStruct *(*(*implementation)())(DummyStruct *dummy_struct);
    _narmock_params_type_for_return_add_one last_call;
};

_narmock_state_type_for_return_add_one *_narmock_mock_return_function_for_return_add_one(DummyStruct *(*return_value)(DummyStruct *dummy_struct));
_narmock_state_type_for_return_add_one *_narmock_mock_implementation_function_for_return_add_one(DummyStruct *(*(*implementation)())(DummyStruct *dummy_struct));
_narmock_state_type_for_return_add_one *_narmock_disable_mock_function_for_return_add_one();

_narmock_private_state_type_for_return_add_one _narmock_state_for_return_add_one =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_return_add_one,
        .mock_implementation = _narmock_mock_implementation_function_for_return_add_one,
        .disable_mock = _narmock_disable_mock_function_for_return_add_one,
        .last_call = NULL
    },

    .mode = 0
};

DummyStruct *(*__wrap_return_add_one())(DummyStruct *dummy_struct)
{
    DummyStruct *(*return_value)(DummyStruct *dummy_struct);

    switch (_narmock_state_for_return_add_one.mode)
    {
        case 1:
            return_value =
            _narmock_state_for_return_add_one.return_value;
            break;
        case 2:
            return_value =
            _narmock_state_for_return_add_one.implementation();
            break;
        default:
            return_value =
            __real_return_add_one();
            break;
    }

    _narmock_params_type_for_return_add_one last_call = { return_value };

    _narmock_state_for_return_add_one.last_call = last_call;
    _narmock_state_for_return_add_one.public.last_call = &_narmock_state_for_return_add_one.last_call;

    return return_value;
}

_narmock_state_type_for_return_add_one *_narmock_mock_return_function_for_return_add_one(DummyStruct *(*return_value)(DummyStruct *dummy_struct))
{
    _narmock_state_for_return_add_one.mode = 1;
    _narmock_state_for_return_add_one.return_value = return_value;

    return &_narmock_state_for_return_add_one.public;
}

_narmock_state_type_for_return_add_one *_narmock_mock_implementation_function_for_return_add_one(DummyStruct *(*(*implementation)())(DummyStruct *dummy_struct))
{
    _narmock_state_for_return_add_one.mode = 2;
    _narmock_state_for_return_add_one.implementation = implementation;

    return &_narmock_state_for_return_add_one.public;
}

_narmock_state_type_for_return_add_one *_narmock_disable_mock_function_for_return_add_one()
{
    _narmock_state_for_return_add_one.mode = 0;

    return &_narmock_state_for_return_add_one.public;
}

_narmock_state_type_for_return_add_one *_narmock_get_mock_for_return_add_one(const void *function)
{
    (void)function;

    return &_narmock_state_for_return_add_one.public;
}

// NARMOCK_IMPLEMENTATION time

time_t __real_time(time_t *arg1);

typedef struct _narmock_private_state_type_for_time _narmock_private_state_type_for_time;

struct _narmock_private_state_type_for_time
{
    _narmock_state_type_for_time public;

    int mode;
    time_t return_value;
    time_t (*implementation)(time_t *arg1);
    _narmock_params_type_for_time last_call;
};

_narmock_state_type_for_time *_narmock_mock_return_function_for_time(time_t return_value);
_narmock_state_type_for_time *_narmock_mock_implementation_function_for_time(time_t (*implementation)(time_t *arg1));
_narmock_state_type_for_time *_narmock_disable_mock_function_for_time();

_narmock_private_state_type_for_time _narmock_state_for_time =
{
    .public = {
        .mock_return = _narmock_mock_return_function_for_time,
        .mock_implementation = _narmock_mock_implementation_function_for_time,
        .disable_mock = _narmock_disable_mock_function_for_time,
        .last_call = NULL
    },

    .mode = 0
};

time_t __wrap_time(time_t *arg1)
{
    time_t return_value;

    switch (_narmock_state_for_time.mode)
    {
        case 1:
            return_value =
            _narmock_state_for_time.return_value;
            break;
        case 2:
            return_value =
            _narmock_state_for_time.implementation(arg1);
            break;
        default:
            return_value =
            __real_time(arg1);
            break;
    }

    _narmock_params_type_for_time last_call = { arg1, return_value };

    _narmock_state_for_time.last_call = last_call;
    _narmock_state_for_time.public.last_call = &_narmock_state_for_time.last_call;

    return return_value;
}

_narmock_state_type_for_time *_narmock_mock_return_function_for_time(time_t return_value)
{
    _narmock_state_for_time.mode = 1;
    _narmock_state_for_time.return_value = return_value;

    return &_narmock_state_for_time.public;
}

_narmock_state_type_for_time *_narmock_mock_implementation_function_for_time(time_t (*implementation)(time_t *arg1))
{
    _narmock_state_for_time.mode = 2;
    _narmock_state_for_time.implementation = implementation;

    return &_narmock_state_for_time.public;
}

_narmock_state_type_for_time *_narmock_disable_mock_function_for_time()
{
    _narmock_state_for_time.mode = 0;

    return &_narmock_state_for_time.public;
}

_narmock_state_type_for_time *_narmock_get_mock_for_time(const void *function)
{
    (void)function;

    return &_narmock_state_for_time.public;
}
