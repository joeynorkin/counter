/*
Filename: decr_hr.c
*/


#include "counter.h"

/*
Decrements cp->hr by hour. Its value will cycle up to MOD_HR-1 for each time it
surpasses the value 0. 

If hour < 0, then cp->hr is incremented by -hour.

parameters:
    hour   (int)  the value of hours to be decremented
*/
void decr_hr(struct count *cp, int hour) {
    int modulo;     /* 0 <= modulo < MOD_HR */
    if (hour > 0) {
        modulo = (cp->hr - hour) % MOD_HR;
        cp->hr = (modulo >= 0) ? modulo : modulo + MOD_HR;
    } else if (hour < 0) {
        incr_hr(cp, -hour);
    }
}