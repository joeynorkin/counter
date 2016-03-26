/*
Filename: incr_hr.c
*/


#include "counter.h"

/*
Increments cp->hr by hour. Its value will cycle back to 0 for each time it
reaches the value MOD_HR.

If hour < 0, then cp->hr is decremented by -hour.
 
parameters:
    hour   (int)  the value of hours to be incremented
*/
void incr_hr(struct count *cp, int hour) {
    if (hour > 0) {
        cp->hr = (cp->hr + hour) % MOD_HR;
    } else if (hour < 0) {
        decr_hr(cp, -hour);
    }
}