#include "counter.h"

void decr_hr(Counter *cp, int hour) {
    int modulo;     /* 0 <= modulo < MOD_HR */
    if (hour > 0) {
        modulo = (cp->hr - hour) % MOD_HR;
        cp->hr = (modulo >= 0) ? modulo : modulo + MOD_HR;
    } else if (hour < 0) {
        incr_hr(cp, -hour);
    }
}
