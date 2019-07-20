ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer
CFLAGS = -Wall -Wextra -std=c11 -g -Og $(ASAN_FLAGS)

.PHONY: test clean format

test: run_tests
	./$<

clean:
	rm -f run_tests

format:
	clang-format -i *.{c,h}

narwhal.c:
	curl -O -sSL https://raw.githubusercontent.com/vberlier/narwhal/master/dist/$@

narwhal.h:
	curl -O -sSL https://raw.githubusercontent.com/vberlier/narwhal/master/dist/$@

__mocks__.c: $(filter-out __mocks__.c,$(wildcard *.c))
	$(CPP) $(CPPFLAGS) $^ | narmock -g $@ -p get_mock_ -p other_mock_prefix_

__mocks__.h: __mocks__.c
	narmock -d $@ $<

run_tests: narwhal.h narwhal.c __mocks__.h __mocks__.c $(wildcard *.c) $(wildcard *.h)
	$(CC) $(CFLAGS) $$(narmock -f __mocks__.h) *.c -o $@
