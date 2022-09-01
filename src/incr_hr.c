#include "counter.h"

void incr_hr(Counter *cp, int hour) {
    if (hour > 0) {
        cp->hr = (cp->hr + hour) % MOD_HR;
    } else if (hour < 0) {
        decr_hr(cp, -hour);
    }
}
