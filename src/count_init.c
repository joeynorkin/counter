#include <stdlib.h>
#include "counter.h"

void count_init(Counter *cp) {
    reset(cp);
}

Counter* counter_create() {
    Counter *cp = (Counter*) malloc(sizeof(Counter));
    reset(cp);
    return cp;
}

void counter_dest(Counter *cp) {
    if (cp) {
        free(cp);
    }
}

void reset(Counter *cp) {
    cp->hr  = 0;
    cp->min = 0;
    cp->sec = 0;
}
