test: test.c libcounter.a
	gcc -o test test.c -L. -lcounter

libcounter.a: count_init.o decr_hr.o decr_min.o decr_sec.o \
				incr_hr.o incr_min.o incr_sec.o display.o
	ar rcs libcounter.a count_init.o decr_hr.o decr_min.o decr_sec.o \
		incr_hr.o incr_min.o incr_sec.o display.o 

count_init.o: count_init.c counter.h
	gcc -c count_init.c

decr_hr.o: decr_hr.c counter.h
	gcc -c decr_hr.c

decr_min.o: decr_min.c counter.h
	gcc -c decr_min.c

decr_sec.o: decr_sec.c counter.h
	gcc -c decr_sec.c

incr_hr.o: incr_hr.c counter.h
	gcc -c incr_hr.c

incr_min.o: incr_min.c counter.h
	gcc -c incr_min.c

incr_sec.o: incr_sec.c counter.h
	gcc -c incr_sec.c

display.o: display.c counter.h
	gcc -c display.c

clean:
	rm test count_init.o decr_hr.o decr_min.o decr_sec.o \
				incr_hr.o incr_min.o incr_sec.o display.o