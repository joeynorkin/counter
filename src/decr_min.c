#include "counter.h"

void decr_min(Counter *cp, int minute) {
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
