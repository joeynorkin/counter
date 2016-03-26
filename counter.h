/*
This is a header file for the counter library
*/

#ifndef COUNTER_H_
#define COUNTER_H_

#include <stdio.h>          /* for output */

#define MOD_HR      24      /* overlap value for hr */
#define MOD_MIN     60      /* overlap value for min */
#define MOD_SEC     60      /* overlap value for sec */
#define MOD_HR_STD  12      /* overlap value for hr for display_std() */



/*
This is a structure used in counter library functions.

Variables hr, min, and sec correspond to the usual rules which regulate hour,
minutes and seconds of a clock.
*/
struct count {
    int hr;
    int min;
    int sec;
};



/* function declarations */



/*
Initializes struct count pointed by cp.

parameters:
    cp  (struct count *)    pointer to count struct to be initialized
    hour    (int)           initial value of cp->hr
    minute  (int)           initial value of cp->min
    second  (int)           initial value of co->sec

Function will accept any int value for hour, minute, and second, but will deal
with the *usual* rules of over/underlapping (the rules followed by the
incrementing/decrementing functions).
*/
void count_init(struct count *cp, int hour, int minute, int second);


/*
Increments cp->hr by hour. Its value will cycle back to 0 for each time it
reaches the value MOD_HR.

If hour < 0, then cp->hr is decremented by -hour.
 
parameters:
    hour   (int)  the value of hours to be incremented
*/
void incr_hr(struct count *cp, int hour);


/*
Increments cp->min by minute. Its value will cycle back to 0 for each time it
reaches the value MOD_MIN, updating cp->hr appropriately.

If minute < 0, the cp->min is decremented by -minute.

parameters:
    minute   (int)  the value of minutes to be incremented
*/
void incr_min(struct count *cp, int minute);


/*
Increments cp->sec by second. Its value will cycle back to 0 for each time it
reaches the value MOD_SEC, updating cp->min and cp->hr appropriately.

If second < 0, the cp->sec is decremented by -second.

parameters:
    second   (int)  the value of seconds to be incremented
*/
void incr_sec(struct count *cp, int second);


/*
Decrements cp->hr by hour. Its value will cycle up to MOD_HR-1 for each time it
surpasses the value 0. 

If hour < 0, then cp->hr is incremented by -hour.

parameters:
    hour   (int)  the value of hours to be decremented
*/
void decr_hr(struct count *cp, int hour);


/*
Decrements cp->min by minute. Its value will cycle up to MOD_MIN-1 for each
time it surpasses the value 0, updating cp->hr appropriately.

If minute < 0, the cp->min is incremented by -minute.

parameters:
    minute   (int)  the value of minutes to be decremented
*/
void decr_min(struct count *cp, int minute);


/*
Decrements cp->sec by second. Its value will cycle up to MOD_SEC-1 for each
time it surpasses the value 0, updating cp->min and cp->hr appropriately.

If second < 0, the cp->sec is incremented by -second.

parameters:
    second   (int)  the value of seconds to be decremented
*/
void decr_sec(struct count *cp, int second);


/*
Displays counter content. Formatted as standard time.
*/
void display_std(struct count counter);


/*
Displays counter content. Formatted as military time.
*/
void display_mil(struct count counter);

#endif
