/*
Filename: decr_min.c
*/


#include "counter.h"

/*
Decrements cp->min by minute. Its value will cycle up to MOD_MIN-1 for each
time it surpasses the value 0, updating cp->hr appropriately.

If minute < 0, the cp->min is incremented by -minute.

parameters:
    minute   (int)  the value of minutes to be decremented
*/
void decr_min(struct count *cp, int minute) {
    int hour_dec;   /* hours to decrement */

    if (minute > 0) {
        minute = cp->min - minute;
        if (minute >= 0) {
            cp->min = minute;
        } else /* decrement hours due to underlap */ {
            /*
            We are dealing with the special case when decrementing minutes
            results in cp->min = 0, to prevent decrementing an extra hour.
            */
            hour_dec = (-minute % MOD_MIN == 0) ? 
                (-minute / MOD_MIN) : (-minute / MOD_MIN) + 1;

            minute = -minute % MOD_MIN; /* number of minutes to subtract after underlap */

            /*
            "% MOD_MIN" is required for when there are NO minutes to subtract
            following overlap, so that 0 is stored in cp->min instead of 60
            */
            cp->min = (MOD_MIN - minute) % MOD_MIN;

            decr_hr(cp, hour_dec);
        }
    } else if (minute < 0) {
        incr_min(cp, -minute);
    }
}