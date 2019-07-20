#include <sys/mount.h>
#include <time.h>
#include <unistd.h>

#include "__mocks__.h"
#include "dummy_functions.h"
#include "narwhal.h"

TEST(mock_getters)
{
    ASSERT_NE(narmock_add(), NULL);

    ASSERT_EQ(narmock_add(), get_mock_add());
    ASSERT_EQ(get_mock_add(), other_mock_prefix_add());
}

TEST(narwhal_mock_macro)
{
    ASSERT_EQ(MOCK(add), narmock_add());
}

int fake_add(int x, int y)
{
    return x + y + 1;
}

TEST(add_function)
{
    MOCK(add)->mock_return(42);
    ASSERT_EQ(add(1, 2), 42);

    MOCK(add)->disable_mock();
    ASSERT_EQ(add(1, 2), 3);

    MOCK(add)->mock_implementation(fake_add);
    ASSERT_EQ(add(1, 2), 4);
}

void fake_output_message(char *message)
{
    printf("fake %s\n", message);
}

TEST(output_message_function)
{
    CAPTURE_OUTPUT(original_output) { output_message("hello"); }
    ASSERT_EQ(original_output, "hello\n");

    MOCK(output_message)->mock_return();

    CAPTURE_OUTPUT(mocked_output) { output_message("hello"); }
    ASSERT_EQ(mocked_output, "");

    MOCK(output_message)->mock_implementation(fake_output_message);

    CAPTURE_OUTPUT(fake_output) { output_message("hello"); }
    ASSERT_EQ(fake_output, "fake hello\n");
}

TEST(time_function)
{
    time_t start = time(NULL);

    MOCK(time)->mock_return(0);
    ASSERT_EQ(time(NULL), 0);

    MOCK(time)->disable_mock();
    ASSERT_GE(time(NULL), start);
}

TEST(pipe_function)
{
    MOCK(pipe)->mock_return(42);

    int fd[2] = { 0, 0 };

    ASSERT_EQ(pipe(fd), 42);
    ASSERT_EQ(fd[0], 0);
    ASSERT_EQ(fd[1], 0);

    MOCK(pipe)->disable_mock();

    ASSERT_EQ(pipe(fd), 0);
    ASSERT_NE(fd[0], 0);
    ASSERT_NE(fd[1], 0);

    close(fd[0]);
    close(fd[1]);
}

TEST(mount_function)
{
    ASSERT_EQ(mount("a", "b", "c", 0, ""), -1);

    MOCK(mount)->mock_return(0);

    ASSERT_EQ(mount("a", "b", "c", 0, ""), 0);
}

DummyStruct *fake_edit_number(DummyStruct *dummy_struct, int number)
{
    dummy_struct->number = 2 * number;
    return dummy_struct + 1;
}

TEST(edit_number_function)
{
    DummyStruct array[] = { { .number = 1 }, { .number = 2 } };
    DummyStruct *dummy_ptr = edit_number(&array[0], 42);

    ASSERT_EQ(dummy_ptr, &array[0]);
    ASSERT_EQ(array[0].number, 42);

    MOCK(edit_number)->mock_implementation(fake_edit_number);

    dummy_ptr = edit_number(&array[0], -1);

    ASSERT_EQ(dummy_ptr, &array[1]);
    ASSERT_EQ(array[0].number, -2);
}

TEST(compose_twice_function)
{
    DummyStruct dummy_struct = { .number = 1 };
    DummyStruct *dummy_ptr = compose_twice(&dummy_struct, add_one);

    ASSERT_EQ(dummy_struct.number, 3);

    MOCK(compose_twice)->mock_return(&dummy_struct);

    ASSERT_EQ(compose_twice(dummy_ptr, add_one), dummy_ptr);
    ASSERT_EQ(dummy_struct.number, 3);
}

int main()
{
    return RUN_TESTS(mock_getters,
                     narwhal_mock_macro,
                     add_function,
                     output_message_function,
                     time_function,
                     pipe_function,
                     mount_function,
                     edit_number_function,
                     compose_twice_function);
}
