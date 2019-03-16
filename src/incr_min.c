/*
Filename: incr_min.c
*/


#include "counter.h"

/*
Increments cp->min by minute. Its value will cycle back to 0 for each time it
reaches the value MOD_MIN, updating cp->hr appropriately.

If minute < 0, the cp->min is decremented by -minute.

parameters:
    minute   (int)  the value of minutes to be incremented
*/
void incr_min(struct count *cp, int minute) {
    int hour_inc; /* hours to add if minute >= MOD_MIN */
    int hr;
    if (minute > 0) {
        minute += cp->min;

        hour_inc = minute / MOD_MIN;
        minute %= MOD_MIN;

        cp->min = minute;
        incr_hr(cp, hour_inc);
    } else if (minute < 0) {
        decr_min(cp, -minute);
    }
}
