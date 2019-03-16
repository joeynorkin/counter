CC 		:= gcc
CFLAGS	:= -W -Wall -Werror
LDFLAGS	:= -L. -lcounter
VPATH 	:= src

all: libcounter.a

test: test.c libcounter.a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<
	./$@
	$(RM) $@

libcounter.a: count_init.o decr_hr.o decr_min.o decr_sec.o \
				incr_hr.o incr_min.o incr_sec.o display.o
	ar rcs libcounter.a count_init.o decr_hr.o decr_min.o decr_sec.o \
		incr_hr.o incr_min.o incr_sec.o display.o

%.o: %.c counter.h
	gcc -c $<

clean:
	$(RM) test libcounter.a count_init.o decr_hr.o decr_min.o decr_sec.o \
				incr_hr.o incr_min.o incr_sec.o display.o
