/* Lighthouse - a lightweight testing framework for C programs. */
/* To run:
 *      1. Copy this file to the folder containing your tests
 *      2. Add '#include "lighthouse.h"' to the top of your test file
 *      3. Write your tests according to the API reference
 *      4. Compile your test file with 'gcc -rdynamic filename.c -o test'
 *      5. Run your tests on the command line with './test'
 *
 *      See the GitHub page for the API reference. */

#ifndef LIGHTHOUSE_H
#define LIGHTHOUSE_H

#include <stdlib.h>
#include <stdio.h>
#include <execinfo.h>

// Define colors for terminal output
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define RESET "\x1B[0m"

/* Macro to run a test function. Keeps track of total test count. Calls setup
 * and teardown functions.*/

#define run(test_func) {_errors = 0; _test_count++; (*_setup_func)(); \
    test_func(); (*_teardown_func)();} 


/* Macro to keep track of failed tests. Increments failed_test_count and prints
 * failure message to console. */

#define FAILED() {_failed_test_count++; printf(KRED "\nFAILED: %s\n" RESET, __func__);}


/* Macro to cause a test failure if an assert condition returns false. Keeps
 * track of the number of assertion errors in a function and causes the test to
 * fail if the error count is nonzero. */

#define assert(condition) {if (!(condition)) {FAILED(); _errors++; ASSERTION_ERROR; return;}}


/* Macro to print an assertion error to the screen including the line number on
 * which the assertion error occurred. */

#define ASSERTION_ERROR printf(KRED "\tAssertion Error: line %i\n" RESET, __LINE__);


/* Stores the setup function to be run before each function. */

#define before(func_name) {_setup_func = &func_name;}


/* Stores the teardown function to be run after each function. */

#define after(func_name) {_teardown_func = &func_name;}


/* Error counter. */
int _errors = 0;

/* Setup and teardown function pointers. */
void (*_setup_func)(void) = NULL;
void (*_teardown_func)(void) = NULL;

/* Variables to count tests run */
int _test_count = 0;
int _failed_test_count = 0;


/* This function prints a summary of your test results to the terminal. */
void print_testing_summary() {

    /* Set output color to red if there are any failed tests or green if all
     * tests pass. */
    if ((_failed_test_count) != 0) {
        printf(KRED);
    } else {
        printf(KGRN);
    }

    printf("\n\n******************** TESTING SUMMARY ****************\n");
    printf("\nRan %d tests: ", _test_count);
    printf("Passed: %d | Failed: %d\n\n", _test_count - _failed_test_count,
        _failed_test_count);
    printf("*****************************************************\n\n");

    /* Reset terminal output color to normal. */
    printf(RESET);
}
#endif
