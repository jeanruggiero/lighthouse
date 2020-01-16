/* Example file showing usage of Lighthouse test framework. */
/* Compile with gcc -rdynamic tests.c -o test for proper output. */

#include <stdio.h>  // For IO operations
//#include <stdlib.h> // for malloc/free

/* This adds Lighthouse to your project. */
#include "lighthouse.h"

/*********************************** IMPLEMENTATION *************************/
/* Normally, you would separate your implementation and tests into separate
 * files, but since this is a small example, we'll lump them together. */

/* This function takes an integer indicating the day of the week and returns 1
 * (true) or 0 (false) indicating whether or not it is the weekend. */
int is_weekend(int day) {
    if ((day >= 0) && (day < 5)) {
        return 0;
    } else {
        return 1;
    }
}

/************************************ TESTS ******************************/

int test_is_weekend_with_weekday() {    // Test return type must be int
    assert(is_weekend(3) == 0);
}

int test_is_weekend_with_monday() {
    assert(is_weekend(0) == 0);
}

int test_is_weekend_with_friday() {
    assert(is_weekend(4) == 0);
}

int test_is_weekend_with_weekend() {
    assert(is_weekend(6) == 1);
}

int test_is_weekend_with_invalid_input() {
    assert(is_weekend(7) == -1);
}

int test_is_weekend_with_negative_number() {
    assert(is_weekend(-1) == -1);
}

/*********************************** RUN TESTS ****************************/
int main(){

    /* For each test you'd like to run, call run() with a pointer to the
     * function (the function name preceeded by &). */
    run(test_is_weekend_with_weekday);
    run(test_is_weekend_with_monday);
    run(test_is_weekend_with_friday);
    run(test_is_weekend_with_weekend);
    run(test_is_weekend_with_invalid_input);
    run(test_is_weekend_with_negative_number);

    /* This is a function provided by Lighthouse to display a summary of your
     * test results, including number of tests run, passed, and failed. */
    print_testing_summary();

    return 0;
}
