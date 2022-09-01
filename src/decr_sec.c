#include "counter.h"

void decr_sec(Counter *cp, int second) {
    int min_dec;   /* min to decrement */

    if (second > 0) {
        second = cp->sec - second;
        if (second >= 0) {
            cp->sec = second;
        } else /* decrement hours due to underlap */ {
            /*
            We are dealing with the special case when decrementing second
            results in cp->sec = 0, to prevent decrementing an extra minute.
            */
            min_dec = (-second % MOD_SEC == 0) ?
                (-second / MOD_SEC) : (-second / MOD_SEC) + 1;

            second = -second % MOD_SEC; /* number of minutes to subtract after underlap */

            /*
            "% MOD_MIN" is required for when there are NO minutes to subtract
            following overlap, so that 0 is stored in cp->sec instead of 60
            */
            cp->sec = (MOD_SEC - second) % MOD_SEC;

            decr_min(cp, min_dec);
        }
    } else if (second < 0) {
        incr_sec(cp, -second);
    }
}
