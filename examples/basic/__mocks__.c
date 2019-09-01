/*
Mocks source file

Generated with Narmock v0.2.1 (https://github.com/vberlier/narmock)
Do not edit manually
*/

#include "__mocks__.h"

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
        .call_count = 0,
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

    _narmock_state_for_time.public.call_count++;

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
