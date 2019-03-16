/*

Filename: test.c

Unit tests for the counter library.

Tests for overlapping, underlapping, incrementing and decrementing various
numbers.

*/


#include "../src/counter.h"
#include <assert.h>

int main() {
    struct count counter;
    count_init(&counter, 0, 0, 0);

    printf("\nBegin unit tests.\n\n");



/*
Begin Hour increment tests
*/

    /*
    incrementing non-negative integers
    */
    incr_hr(&counter, 0);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, MOD_HR);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, 1);
    assert(1 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, 2);
    assert(3 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, 20);
    assert(23 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, 150);
    assert(5 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);



    count_init(&counter, 0, 0, 0); /* back to all zeros for more testing */


    /*
    incrementing negative integers
    */

    incr_hr(&counter, -MOD_HR);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, -1);
    assert(23 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, -2);
    assert(21 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, -20);
    assert(1 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_hr(&counter, -150);
    assert(19 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

/*
End Hour increment test
 */


    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


/*
Begin Hour decrement test
*/

    /*
    decrementing non-negative integers
    */
    decr_hr(&counter, 0);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, MOD_HR);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, 1);
    assert(23 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, 2);
    assert(21 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, 20);
    assert(1 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, 150);
    assert(19 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);



    count_init(&counter, 0, 0, 0); /* back to all zeros for more testing */


    /*
    decrementing negative integers
    */
    decr_hr(&counter, -MOD_HR);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, -1);
    assert(1 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, -2);
    assert(3 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, -20);
    assert(23 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_hr(&counter, -150);
    assert(5 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

/*
End Hour decrement test
*/


    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


/*
Begin minute increment test
*/

    /*
    incrementing non-negative integers
    */
    incr_min(&counter, 0);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, MOD_MIN);
    assert(1 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, 1);
    assert(1 == counter.hr);
    assert(1 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, 2);
    assert(1 == counter.hr);
    assert(3 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, 50);
    assert(1 == counter.hr);
    assert(53 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, 100);
    assert(3 == counter.hr);
    assert(33 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, 1273);
    assert(0 == counter.hr);
    assert(46 == counter.min);
    assert(0 == counter.sec);



    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


    /*
    incrementing negative integers
    */
    incr_min(&counter, -MOD_MIN);
    assert(23 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, -1);
    assert(22 == counter.hr);
    assert(59 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, -2);
    assert(22 == counter.hr);
    assert(57== counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, -50);
    assert(22 == counter.hr);
    assert(7 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, -100);
    assert(20 == counter.hr);
    assert(27 == counter.min);
    assert(0 == counter.sec);

    incr_min(&counter, -1273);
    assert(23 == counter.hr);
    assert(14 == counter.min);
    assert(0 == counter.sec);

/*
End minute increment test
*/


    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


/*
Begin minute decrement test
*/

    /*
    decrementing non-negative integers
    */
    decr_min(&counter, 0);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, MOD_MIN);
    assert(23 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, 1);
    assert(22 == counter.hr);
    assert(59 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, 2);
    assert(22 == counter.hr);
    assert(57 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, 50);
    assert(22 == counter.hr);
    assert(7 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, 100);
    assert(20 == counter.hr);
    assert(27 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, 1273);
    assert(23 == counter.hr);
    assert(14 == counter.min);
    assert(0 == counter.sec);



    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


    /*
    decrementing negative integers
    */
    decr_min(&counter, -MOD_MIN);
    assert(1 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, -1);
    assert(1 == counter.hr);
    assert(1 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, -2);
    assert(1 == counter.hr);
    assert(3 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, -50);
    assert(1 == counter.hr);
    assert(53 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, -100);
    assert(3 == counter.hr);
    assert(33 == counter.min);
    assert(0 == counter.sec);

    decr_min(&counter, -1273);
    assert(0 == counter.hr);
    assert(46 == counter.min);
    assert(0 == counter.sec);


/*
End Minute decrement test
*/


    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


/*
Begin second increment test
*/

    /*
    incrementing non-negative integers
    */
    incr_sec(&counter, 0);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    incr_sec(&counter, MOD_SEC);
    assert(0 == counter.hr);
    assert(1 == counter.min);
    assert(0 == counter.sec);

    incr_sec(&counter, 1);
    assert(0 == counter.hr);
    assert(1 == counter.min);
    assert(1 == counter.sec);

    incr_sec(&counter, 2);
    assert(0 == counter.hr);
    assert(1 == counter.min);
    assert(3 == counter.sec);

    incr_sec(&counter, 50);
    assert(0 == counter.hr);
    assert(1 == counter.min);
    assert(53 == counter.sec);

    incr_sec(&counter, 100);
    assert(0 == counter.hr);
    assert(3 == counter.min);
    assert(33 == counter.sec);

    incr_sec(&counter, 3421);
    assert(1 == counter.hr);
    assert(0 == counter.min);
    assert(34 == counter.sec);



    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


    /*
    incrementing negative integers
    */
    incr_sec(&counter, -MOD_SEC);
    assert(23 == counter.hr);
    assert(59 == counter.min);
    assert(0 == counter.sec);

    incr_sec(&counter, -1);
    assert(23 == counter.hr);
    assert(58 == counter.min);
    assert(59 == counter.sec);

    incr_sec(&counter, -2);
    assert(23 == counter.hr);
    assert(58 == counter.min);
    assert(57 == counter.sec);

    incr_sec(&counter, -50);
    assert(23 == counter.hr);
    assert(58 == counter.min);
    assert(7 == counter.sec);

    incr_sec(&counter, -100);
    assert(23 == counter.hr);
    assert(56 == counter.min);
    assert(27 == counter.sec);

    incr_sec(&counter, -3421);
    assert(22 == counter.hr);
    assert(59 == counter.min);
    assert(26 == counter.sec);


/*
End second increment test
*/


    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


/*
Begin second decrement test
*/

    /*
    decrementing non-negative integers
    */
    decr_sec(&counter, 0);
    assert(0 == counter.hr);
    assert(0 == counter.min);
    assert(0 == counter.sec);

    decr_sec(&counter, MOD_SEC);
    assert(23 == counter.hr);
    assert(59 == counter.min);
    assert(0 == counter.sec);

    decr_sec(&counter, 1);
    assert(23 == counter.hr);
    assert(58 == counter.min);
    assert(59 == counter.sec);

    decr_sec(&counter, 2);
    assert(23 == counter.hr);
    assert(58 == counter.min);
    assert(57 == counter.sec);

    decr_sec(&counter, 50);
    assert(23 == counter.hr);
    assert(58 == counter.min);
    assert(7 == counter.sec);

    decr_sec(&counter, 100);
    assert(23 == counter.hr);
    assert(56 == counter.min);
    assert(27 == counter.sec);

    decr_sec(&counter, 3421);
    assert(22 == counter.hr);
    assert(59 == counter.min);
    assert(26 == counter.sec);



    count_init(&counter, 0, 0, 0);  /* back to all zeros for more testing */


    /*
    decrementing negative integers
    */
    decr_sec(&counter, -MOD_SEC);
    assert(0 == counter.hr);
    assert(1 == counter.min);
    assert(0 == counter.sec);

    decr_sec(&counter, -1);
    assert(0 == counter.hr);
    assert(1 == counter.min);
    assert(1 == counter.sec);

    decr_sec(&counter, -2);
    assert(0 == counter.hr);
    assert(1 == counter.min);
    assert(3 == counter.sec);

    decr_sec(&counter, -50);
    assert(0 == counter.hr);
    assert(1 == counter.min);
    assert(53 == counter.sec);

    decr_sec(&counter, -100);
    assert(0 == counter.hr);
    assert(3 == counter.min);
    assert(33 == counter.sec);

    decr_sec(&counter, -3421);
    assert(1 == counter.hr);
    assert(0 == counter.min);
    assert(34 == counter.sec);

/*
End second decrement test
*/

    printf("All tests passed!\n\n");

    return 0;
}
