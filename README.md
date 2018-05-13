# Counter Library

## DESCRIPTION
This is a counter library that provides an accumulator which can be incremented
and decremented.

Accumulator is formatted like a clock. There are units called "hour", "minute"
and "second", all relating as one can expect for a clock. For example, when
"second" reaches 60, it cycles back to 0 while "minute" increments and so on.
The library is configurable. 60, 60, and 24 are the default values where "second",
"minute", and "hour" cycle back to 0, respectively. These values can be changed
by the wish of the programmer.

### To use the counter library
Run the makefile in the counter directory (which is the default directory when
pulling or downloading from the github repository). This will compile the library
file (as well as the object files and an executable, *test*, which performs unit
tests to ensure correct functionality of the library).
Include the header file *counter.h* in the program using the library and when
compiling, include the segment:

    -L. -lcounter

For simplicity, this assumes both the header and library files are in your
current directory.

Make sure you declare and initialize a struct count variable to use the
functions. This can be done as such

    struct count counter;
    count_init(&counter, 0, 0, 0);



## FUNCTIONS
For more details, refer to the function declarations in the header file.

### count_init
    initializes the variables of the struct count variable.

### incr_hr, incr_min, incr_sec
    all increment the variables of the struct count variable by any integer x. \
    If x < 0, then these incrementing functions will increment by x's negative \
    value, or in other words, will decrement the values by -x. So incrementing \
    by -number can be viewed as decrementing by number.


### decr_hr, decr_min, decr_sec
    all decrement the variables of the struct count variable by any integer x. \
    If x < 0, then these decrementing functions will decrement by x's negative \
    value, or in other words, will increment the values by -x. So decrementing \
    by -number can be viewed as incrementing by number.

### display_std, display_mil
    display the contents of the struct count variable, formatted like a clock. \
    display_std corresponds to the standard time format and display_mil \
    corresponds to military time format.



## FILES
Each function of the library are in their own separate c file, with the exact name
as the function with an exception for the display functions, which are both in display.c

### counter.h
    Header file, declares the struct count variable and library functions.

### test.c
    Implements unit tests of the counter library.

### libcounter.a
    Static library file of the counter library.

### makefile
    Compiles libcounter.a and the object files of the library functions. Compiles \
    executable, test, a program which runs unit tests.


## Compiler
Apple LLVM version 7.0.2 (clang-700.1.81)



## AUTHOR
Joey Norkin
joey.norkin@gmail.com
