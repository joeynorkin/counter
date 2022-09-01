#include "counter.h"

void incr_sec(Counter *cp, int sec) {
    int min_inc; /* hours to add if second >= MOD_SEC */
    if (sec < 0) {
        decr_sec(cp, -sec);
    } else {
        sec += cp->sec;

        min_inc = sec / MOD_SEC;
        sec %= MOD_SEC;

        cp->sec = sec;
        incr_min(cp, min_inc);
    }
}
