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

#define run(test_func) {errors = 0; test_count++; test_func();}
#define FAILED() {failed_test_count++; printf(KRED "\nFAILED: %s\n" RESET, __func__);}

#define assert(condition) {if (!(condition)) {FAILED(); errors++; ASSERTION_ERROR; return;}}

#define ASSERTION_ERROR printf(KRED "\tAssertion Error: line %i\n" RESET, __LINE__);

/* Error counter. */
int errors = 0;

// Global variables to count tests run
int test_count = 0;
int failed_test_count = 0;


/* This function prints a summary of your test results to the terminal. */
void print_testing_summary() {

    /* Set output color to red if there are any failed tests or green if all
     * tests pass. */
    if ((failed_test_count) != 0) {
        printf(KRED);
    } else {
        printf(KGRN);
    }

    printf("\n\n******************** TESTING SUMMARY ****************\n");
    printf("\nRan %d tests: ", test_count);
    printf("Passed: %d | Failed: %d\n\n", test_count - failed_test_count,
        failed_test_count);
    printf("*****************************************************\n\n");

    /* Reset terminal output color to normal. */
    printf(RESET);
}
#endif
