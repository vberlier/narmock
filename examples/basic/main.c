#include <time.h>

#include "__mocks__.h"
#include "narwhal.h"

TEST(example)
{
    MOCK(time)->mock_return(42);
    ASSERT_EQ(time(NULL), 42);
}

int main(void)
{
    return RUN_TESTS(example);
}
