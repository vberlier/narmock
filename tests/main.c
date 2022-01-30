#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mount.h>
#include <time.h>
#include <unistd.h>

#include "__mocks__.h"
#include "dummy_functions.h"
#include "narwhal.h"

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

void fake_output_message(const char *message)
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

TEST(print_hello_function)
{
    CAPTURE_OUTPUT(original_output) { print_hello(); }
    ASSERT_EQ(original_output, "hello\n");

    MOCK(print_hello)->mock_return();

    CAPTURE_OUTPUT(mocked_output) { print_hello(); }
    ASSERT_EQ(mocked_output, "");

    MOCK(print_hello)->mock_implementation(print_world);

    CAPTURE_OUTPUT(other_output) { print_hello(); }
    ASSERT_EQ(other_output, "world\n");
}

TEST(print_world_function)
{
    CAPTURE_OUTPUT(original_output) { print_world(); }
    ASSERT_EQ(original_output, "world\n");

    MOCK(print_world)->mock_return();

    CAPTURE_OUTPUT(mocked_output) { print_world(); }
    ASSERT_EQ(mocked_output, "");

    MOCK(print_world)->mock_implementation(print_hello);

    CAPTURE_OUTPUT(other_output) { print_world(); }
    ASSERT_EQ(other_output, "hello\n");
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

    MOCK(mount)->reset();

    ASSERT_EQ(MOCK(mount)->call_count, 0);
    ASSERT_EQ(MOCK(mount)->last_call, NULL);

    ASSERT_EQ(mount("a", "b", "c", 0, ""), -1);
    ASSERT_EQ(MOCK(mount)->last_call->errsv, ENOENT);
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

DummyStruct *(*fake_return_add_one())(DummyStruct *dummy_struct)
{
    return NULL;
}

TEST(return_add_one_function)
{
    DummyStruct dummy_struct = { .number = 1 };

    ASSERT_EQ(return_add_one()(&dummy_struct)->number, 2);

    MOCK(return_add_one)->mock_return(add_two);
    ASSERT_EQ(return_add_one()(&dummy_struct)->number, 4);

    MOCK(return_add_one)->mock_implementation(fake_return_add_one);
    ASSERT_EQ(return_add_one(), NULL);
}

TEST(add_function_call_count)
{
    ASSERT_EQ(MOCK(add)->call_count, 0);

    for (int i = 0; i < 10; i++)
    {
        ASSERT_EQ(add(i, i * 2), 3 * i);
    }

    ASSERT_EQ(MOCK(add)->call_count, 10);

    MOCK(add)->reset();

    ASSERT_EQ(MOCK(add)->call_count, 0);
}

TEST(add_function_last_call)
{
    ASSERT_EQ(MOCK(add)->last_call, NULL);

    ASSERT_EQ(add(1, 2), 3);

    ASSERT_NE(MOCK(add)->last_call, NULL);
    ASSERT_EQ(MOCK(add)->last_call->arg1, 1);
    ASSERT_EQ(MOCK(add)->last_call->arg2, 2);
    ASSERT_EQ(MOCK(add)->last_call->return_value, 3);

    ASSERT_EQ(add(23, 19), 42);

    ASSERT_EQ(MOCK(add)->last_call->arg1, 23);
    ASSERT_EQ(MOCK(add)->last_call->arg2, 19);
    ASSERT_EQ(MOCK(add)->last_call->return_value, 42);
}

TEST(time_function_last_call)
{
    ASSERT_EQ(MOCK(time)->last_call, NULL);

    time_t current_time = time(NULL);

    ASSERT_EQ(MOCK(time)->last_call->arg1, NULL);
    ASSERT_EQ(MOCK(time)->last_call->return_value, current_time);

    MOCK(time)->reset();

    ASSERT_EQ(MOCK(time)->last_call, NULL);
}

TEST(add_one_function_last_call)
{
    ASSERT_EQ(MOCK(add_one)->last_call, NULL);

    DummyStruct dummy_struct = { .number = 1 };

    ASSERT_EQ(add_one(&dummy_struct)->number, 2);

    ASSERT_NE(MOCK(add_one)->last_call, NULL);
    ASSERT_EQ(MOCK(add_one)->last_call->arg1, &dummy_struct);
    ASSERT_EQ(MOCK(add_one)->last_call->return_value, &dummy_struct);
}

TEST(write_function)
{
    MOCK(write)->mock_return(64);

    ASSERT_EQ(write(1234, NULL, 8), 64);
}

TEST(keep_args_output_message_function)
{
    MOCK(keep_args_output_message)->mock_return();

    keep_args_output_message("foo");

    ASSERT_EQ(MOCK(keep_args_output_message)->last_call->message, "foo");
}

TEST(fopen_with_errno)
{
    MOCK(fopen)->mock_return(NULL)->mock_errno(ENOENT);

    FILE *f = fopen(__FILE__, "r");

    ASSERT_EQ(f, NULL);
    ASSERT_EQ(errno, ENOENT);
    ASSERT_EQ(MOCK(fopen)->last_call->errsv, ENOENT);

    CAPTURE_OUTPUT(output) { warn("fopen"); }

    ASSERT_EQ(output, "run_tests: fopen: No such file or directory\n");

    MOCK(fopen)->disable_mock();

    errno = 0;

    f = fopen(__FILE__, "r");
    ASSERT_NE(f, NULL);
    fclose(f);

    ASSERT_EQ(errno, 0);
}

TEST(open_function)
{
    MOCK(open)->mock_return(1);

    ASSERT_EQ(open("a", 0), 1);
}
