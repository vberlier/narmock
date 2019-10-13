ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer
CFLAGS = -Wall -Wextra -Wconversion -std=c11 -g -Og $(ASAN_FLAGS)

.PHONY: test clean format

test: run_tests
	./$<

clean:
	rm -f run_tests

format:
	clang-format -i main.c dummy_functions.h dummy_functions.c

narwhal.c narwhal.h:
	curl -O -sSL https://raw.githubusercontent.com/vberlier/narwhal/master/dist/$@

__mocks__%c __mocks__%h: $(filter-out __mocks__%c,$(wildcard *.c))
	$(CPP) $^ | narmock -g -k 'keep_args_.*'

run_tests: narwhal.h narwhal.c __mocks__.h __mocks__.c $(wildcard *.c) $(wildcard *.h)
	$(CC) $(CFLAGS) $$(narmock -f) *.c -o $@
