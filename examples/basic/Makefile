ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer
CFLAGS = -Wall -Wextra -Wconversion -std=c11 -g -Og $(ASAN_FLAGS)

.PHONY: test clean

test: run_tests
	./$<

clean:
	rm -f run_tests

narwhal.c narwhal.h:
	curl -O -sSL https://raw.githubusercontent.com/vberlier/narwhal/master/dist/$@

__mocks__%c __mocks__%h: main.c
	$(CPP) $^ | narmock -g

run_tests: narwhal.h narwhal.c __mocks__.h __mocks__.c main.c
	$(CC) $(CFLAGS) $$(narmock -f) *.c -o $@
