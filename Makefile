CC      := gcc
CFLAGS  := -W -Wall -Werror
LDFLAGS := -L.
LDLIBS  := -lcounter
VPATH   := src

UNIT_TESTS=test/unit_tests

all: libcounter.a

test: test/unit_tests.c libcounter.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(UNIT_TESTS) $<
	./$(UNIT_TESTS)
	$(RM) $(UNIT_TESTS)

libcounter.a: count_init.o decr_hr.o decr_min.o decr_sec.o \
				incr_hr.o incr_min.o incr_sec.o display.o
	$(AR) rcs $@ $^

%.o: %.c counter.h
	$(CC) $< -c

clean:
	$(RM) $(UNIT_TESTS) libcounter.a count_init.o decr_hr.o decr_min.o \
				decr_sec.o incr_hr.o incr_min.o incr_sec.o display.o
