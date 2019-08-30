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

#include <time.h>

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
