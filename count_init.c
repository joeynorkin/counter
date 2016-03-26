/*
Filename: count_init.c
*/


#include "counter.h"

/*
Initializes struct count pointed by cp.

parameters:
	cp	(struct count *)	pointer to count struct to be initialized
	hour	(int)			initial value of cp->hr
	minute	(int)			initial value of cp->min
	second	(int)			initial value of co->sec

Function will accept any int value for hour, minute, and second, but will deal
with the *usual* rules of over/underlapping (the rules followed by the
incrementing/decrementing functions).
*/
void count_init(struct count *cp, int hour, int minute, int second) {
    cp->hr = 0;
    cp->min = 0;
    cp->sec = 0;

    incr_hr(cp, hour);
    incr_min(cp, minute);
    incr_sec(cp, second);
}