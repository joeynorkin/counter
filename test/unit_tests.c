/*

Filename: test.c

Unit tests for the counter library.

Tests for overlapping, underlapping, incrementing and decrementing various
numbers.

*/


#include "../src/counter.h"
#include <stdio.h>
#include <assert.h>

void assertCounterFields(Counter *cp, int expected_hr, int expected_min, int expected_sec) {
    assert(cp->hr == expected_hr);
    assert(cp->min == expected_min);
    assert(cp->sec == expected_sec);
}

int main() {
    Counter *cp = counter_create();
    printf("\nBegin unit tests.\n\n");


/*
Begin Hour increment tests
*/

    /*
    incrementing non-negative integers
    */
    incr_hr(cp, 0);
    assertCounterFields(cp, 0, 0, 0);

    incr_hr(cp, MOD_HR);
    assertCounterFields(cp, 0, 0, 0);

    incr_hr(cp, 1);
    assertCounterFields(cp, 1, 0, 0);

    incr_hr(cp, 2);
    assertCounterFields(cp, 3, 0, 0);

    incr_hr(cp, 20);
    assertCounterFields(cp, 23, 0, 0);

    incr_hr(cp, 150);
    assertCounterFields(cp, 5, 0, 0);


    reset(cp); /* back to all zeros for more testing */


    /*
    incrementing negative integers
    */

    incr_hr(cp, -MOD_HR);
    assertCounterFields(cp, 0, 0, 0);

    incr_hr(cp, -1);
    assertCounterFields(cp, 23, 0, 0);

    incr_hr(cp, -2);
    assertCounterFields(cp, 21, 0, 0);

    incr_hr(cp, -20);
    assertCounterFields(cp, 1, 0, 0);

    incr_hr(cp, -150);
    assertCounterFields(cp, 19, 0, 0);

/*
End Hour increment test
 */


    reset(cp);  /* back to all zeros for more testing */


/*
Begin Hour decrement test
*/

    /*
    decrementing non-negative integers
    */
    decr_hr(cp, 0);
    assertCounterFields(cp, 0, 0, 0);

    decr_hr(cp, MOD_HR);
    assertCounterFields(cp, 0, 0, 0);

    decr_hr(cp, 1);
    assertCounterFields(cp, 23, 0, 0);

    decr_hr(cp, 2);
    assertCounterFields(cp, 21, 0, 0);

    decr_hr(cp, 20);
    assertCounterFields(cp, 1, 0, 0);

    decr_hr(cp, 150);
    assertCounterFields(cp, 19, 0, 0);



    reset(cp); /* back to all zeros for more testing */


    /*
    decrementing negative integers
    */
    decr_hr(cp, -MOD_HR);
    assertCounterFields(cp, 0, 0, 0);

    decr_hr(cp, -1);
    assertCounterFields(cp, 1, 0, 0);

    decr_hr(cp, -2);
    assertCounterFields(cp, 3, 0, 0);

    decr_hr(cp, -20);
    assertCounterFields(cp, 23, 0, 0);

    decr_hr(cp, -150);
    assertCounterFields(cp, 5, 0, 0);

/*
End Hour decrement test
*/


    reset(cp);  /* back to all zeros for more testing */


/*
Begin minute increment test
*/

    /*
    incrementing non-negative integers
    */
    incr_min(cp, 0);
    assertCounterFields(cp, 0, 0, 0);

    incr_min(cp, MOD_MIN);
    assertCounterFields(cp, 1, 0, 0);

    incr_min(cp, 1);
    assertCounterFields(cp, 1, 1, 0);

    incr_min(cp, 2);
    assertCounterFields(cp, 1, 3, 0);

    incr_min(cp, 50);
    assertCounterFields(cp, 1, 53, 0);

    incr_min(cp, 100);
    assertCounterFields(cp, 3, 33, 0);

    incr_min(cp, 1273);
    assertCounterFields(cp, 0, 46, 0);



    reset(cp);  /* back to all zeros for more testing */


    /*
    incrementing negative integers
    */
    incr_min(cp, -MOD_MIN);
    assertCounterFields(cp, 23, 0, 0);

    incr_min(cp, -1);
    assertCounterFields(cp, 22, 59, 0);

    incr_min(cp, -2);
    assertCounterFields(cp, 22, 57, 0);

    incr_min(cp, -50);
    assertCounterFields(cp, 22, 7, 0);

    incr_min(cp, -100);
    assertCounterFields(cp, 20, 27, 0);

    incr_min(cp, -1273);
    assertCounterFields(cp, 23, 14, 0);

/*
End minute increment test
*/


    reset(cp);  /* back to all zeros for more testing */


/*
Begin minute decrement test
*/

    /*
    decrementing non-negative integers
    */
    decr_min(cp, 0);
    assertCounterFields(cp, 0, 0, 0);

    decr_min(cp, MOD_MIN);
    assertCounterFields(cp, 23, 0, 0);

    decr_min(cp, 1);
    assertCounterFields(cp, 22, 59, 0);

    decr_min(cp, 2);
    assertCounterFields(cp, 22, 57, 0);

    decr_min(cp, 50);
    assertCounterFields(cp, 22, 7, 0);

    decr_min(cp, 100);
    assertCounterFields(cp, 20, 27, 0);

    decr_min(cp, 1273);
    assertCounterFields(cp, 23, 14, 0);



    reset(cp);  /* back to all zeros for more testing */


    /*
    decrementing negative integers
    */
    decr_min(cp, -MOD_MIN);
    assertCounterFields(cp, 1, 0, 0);

    decr_min(cp, -1);
    assertCounterFields(cp, 1, 1, 0);

    decr_min(cp, -2);
    assertCounterFields(cp, 1, 3, 0);

    decr_min(cp, -50);
    assertCounterFields(cp, 1, 53, 0);

    decr_min(cp, -100);
    assertCounterFields(cp, 3, 33, 0);

    decr_min(cp, -1273);
    assertCounterFields(cp, 0, 46, 0);


/*
End Minute decrement test
*/


    reset(cp);  /* back to all zeros for more testing */


/*
Begin second increment test
*/

    /*
    incrementing non-negative integers
    */
    incr_sec(cp, 0);
    assertCounterFields(cp, 0, 0, 0);

    incr_sec(cp, MOD_SEC);
    assertCounterFields(cp, 0, 1, 0);

    incr_sec(cp, 1);
    assertCounterFields(cp, 0, 1, 1);

    incr_sec(cp, 2);
    assertCounterFields(cp, 0, 1, 3);

    incr_sec(cp, 50);
    assertCounterFields(cp, 0, 1, 53);

    incr_sec(cp, 100);
    assertCounterFields(cp, 0, 3, 33);

    incr_sec(cp, 3421);
    assertCounterFields(cp, 1, 0, 34);



    reset(cp);  /* back to all zeros for more testing */


    /*
    incrementing negative integers
    */
    incr_sec(cp, -MOD_SEC);
    assertCounterFields(cp, 23, 59, 0);

    incr_sec(cp, -1);
    assertCounterFields(cp, 23, 58, 59);

    incr_sec(cp, -2);
    assertCounterFields(cp, 23, 58, 57);

    incr_sec(cp, -50);
    assertCounterFields(cp, 23, 58, 7);

    incr_sec(cp, -100);
    assertCounterFields(cp, 23, 56, 27);

    incr_sec(cp, -3421);
    assertCounterFields(cp, 22, 59, 26);


/*
End second increment test
*/


    reset(cp);  /* back to all zeros for more testing */


/*
Begin second decrement test
*/

    /*
    decrementing non-negative integers
    */
    decr_sec(cp, 0);
    assertCounterFields(cp, 0, 0, 0);

    decr_sec(cp, MOD_SEC);
    assertCounterFields(cp, 23, 59, 0);

    decr_sec(cp, 1);
    assertCounterFields(cp, 23, 58, 59);

    decr_sec(cp, 2);
    assertCounterFields(cp, 23, 58, 57);

    decr_sec(cp, 50);
    assertCounterFields(cp, 23, 58, 7);

    decr_sec(cp, 100);
    assertCounterFields(cp, 23, 56, 27);

    decr_sec(cp, 3421);
    assertCounterFields(cp, 22, 59, 26);



    reset(cp);  /* back to all zeros for more testing */


    /*
    decrementing negative integers
    */
    decr_sec(cp, -MOD_SEC);
    assertCounterFields(cp, 0, 1, 0);

    decr_sec(cp, -1);
    assertCounterFields(cp, 0, 1, 1);

    decr_sec(cp, -2);
    assertCounterFields(cp, 0, 1, 3);

    decr_sec(cp, -50);
    assertCounterFields(cp, 0, 1, 53);

    decr_sec(cp, -100);
    assertCounterFields(cp, 0, 3, 33);

    decr_sec(cp, -3421);
    assertCounterFields(cp, 1, 0, 34);

    counter_dest(cp);

/*
End second decrement test
*/

    printf("All tests passed!\n\n");

    return 0;
}
