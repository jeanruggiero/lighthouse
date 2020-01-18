/* Example file showing usage of Lighthouse test framework. */
/* Compile with: gcc tests.c -o test */

#include <stdio.h>

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

/* Optional setup and teardown routines. */
void set_up() {
    printf("Do this before each function!\n");
}

void teardown() {
    printf("Do this one after.\n");
}

void test_is_weekend_with_weekday() {
    assert(is_weekend(3) == 0);
}

void test_is_weekend_with_monday() {
    assert(is_weekend(0) == 0);
}

void test_is_weekend_with_friday() {
    assert(is_weekend(4) == 0);
}

void test_is_weekend_with_weekend() {
    assert(is_weekend(6) == 1);
}

void test_is_weekend_with_invalid_input() {
    assert(is_weekend(7) == -1);
}

void test_is_weekend_with_negative_number() {
    assert(is_weekend(-1) == -1);
}

/*********************************** RUN TESTS ****************************/
int main(){

    /* Indicate your setup (before) and teardown (after) functions. */
    before(set_up);
    after(teardown);

    /* For each test you'd like to run, call run() with the name of the test 
     * function to run. */
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
