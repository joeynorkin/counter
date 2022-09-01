#include "counter.h"
#include <stdio.h>

/*
 * Print counter in standard time format.
 */
void display_std(Counter *cp) {
    int hour;
    char *postfix = ( (hour = cp->hr) < 12 ) ? "AM" : "PM";

    hour %= MOD_HR_STD;

    if (hour == 0) hour = 12;

    printf("counter:  %d:%d:%d %s\n", hour, cp->min, cp->sec, postfix);
}

/*
 * Print counter in military time format.
 */
void display_mil(Counter *cp) {
    printf("counter:  %d:%d:%d\n", cp->hr, cp->min, cp->sec);
}
