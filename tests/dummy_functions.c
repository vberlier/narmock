#include "dummy_functions.h"

#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

void output_message(char *message)
{
    printf("%s\n", message);
}

DummyStruct *edit_number(DummyStruct *dummy_struct, int number)
{
    dummy_struct->number = number;
    return dummy_struct;
}

DummyStruct *add_one(DummyStruct *dummy_struct)
{
    dummy_struct->number++;
    return dummy_struct;
}

DummyStruct *compose_twice(DummyStruct *dummy_struct,
                           DummyStruct *(*dummy_struct_modifier)(DummyStruct *dummy_struct))
{
    return dummy_struct_modifier(dummy_struct_modifier(dummy_struct));
}
