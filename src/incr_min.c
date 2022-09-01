#include "counter.h"

void incr_min(Counter *cp, int minute) {
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
