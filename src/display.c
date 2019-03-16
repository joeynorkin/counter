/*
Filename: display.c

Written by Joey Norkin, March 2016
*/


#include "counter.h"

/*
Displays counter content. Formatted as standard time.
*/
void display_std(struct count counter) {
    int hour;

    if (( hour = counter.hr % MOD_HR_STD ) == 0)
        hour = 12;

    printf("counter:  %d:%d:%d\n", hour, counter.min, counter.sec);
}


/*
Displays counter content. Formatted as military time.
*/
void display_mil(struct count counter) {
    printf("counter:  %d:%d:%d\n", counter.hr, counter.min, counter.sec);
}