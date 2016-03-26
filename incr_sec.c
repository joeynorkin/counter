/*
Filename: incr_sec.c
*/


#include "counter.h"

/*
Increments cp->sec by second. Its value will cycle back to 0 for each time it
reaches the value MOD_SEC, updating cp->min and cp->hr appropriately.

If second < 0, the cp->sec is decremented by -second.

parameters:
    second   (int)  the value of seconds to be incremented
*/
void incr_sec(struct count *cp, int second) {
    int min_inc; /* hours to add if second >= MOD_SEC */
    if (second > 0) {
        second += cp->sec;

        min_inc = second / MOD_SEC;
        second %= MOD_SEC;

        cp->sec = second;
        incr_min(cp, min_inc);
    } else if (second < 0) {
        decr_sec(cp, -second);
    }
}