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

int failed(void);
int success(void);
void run(int (*test_func)(void));
void print_testing_summary(void);
char *get_function_name(void);

// Global variables to count tests run
int test_count = 0;
int successful_test_count = 0;
int failed_test_count = 0;

/* Returns 1 if assertion passes, 0 if failed. */
int assert_equals(int a, int b) {
    if (a != b) {
        printf("Assertion error: ");
        return failed();
    } else {
        return 1;
    }
}

/* Helper function that runs test and prints success/fail status. This function
 * also keeps track of how many tests it has run, how many have failed, and how
 * many have passed. In order for it to work, failed tests must return either
 * success() or failed(). */
void run(int (*test_func)(void)) {

    test_count++;

    if ((*test_func)() == 0) {
        /* Test failed. */
        failed_test_count++;
    } else {
        successful_test_count++;
    }
}

/* This function should be called from your test method if you encounter a
 * condition that should cause the test to fail. It prints a message to the
 * terminal with an indication of the failure. */
int failed(void) {
    printf(KRED "\nTEST FAILED: %s\n" RESET, get_function_name());
    return 0;
}

/* This function should be called from your test method if you do not encounter
 * any conditions that should cause your test to fail. It prints a message to
 * the terminal with an indication that the test passed. */
int success(void) {
    printf("\nTEST PASSED: %s\n", get_function_name()); 
    return 1;
}

/* This function queries the callstack and returns the name of the function that
 * called success or failed. It will only work properly if called from within
 * success or failed. */
char *get_function_name() {
    void *callstack[32];
    char **trace;
    char *function_name = (char *) malloc(sizeof(char) * 100);
    int frames = backtrace(callstack, 32);
    char c;
    int i, j;

    /* An array of strings representing the top 3 frames of the callstack. */
    trace = backtrace_symbols(callstack, 3);
   
    /* Parse the 3rd frame, which corresponds to the test function, in order to
     * get the name of the test method that called success or failed. */
    for (i = 0; trace[2][i] != '('; i++) {
        ;
    }

    i++;

    for (j = 0; trace[2][i] != '+'; i++, j++) {
        function_name[j] = trace[2][i];
    }
    function_name[j] = '\0';

    free(trace); 
    return function_name;
}

/* This function prints a summary of your test results to the terminal. */
void print_testing_summary() {

    /* Set output color to red if there are any failed tests or green if all
     * tests pass. */
    if (failed_test_count != 0) {
        printf(KRED);
    } else {
        printf(KGRN);
    }

    printf("\n\n******************** TESTING SUMMARY ****************\n");
    printf("\nRan %d tests: ", test_count);
    printf("Passed: %d | Failed: %d\n\n", successful_test_count,
        failed_test_count);
    printf("*****************************************************\n\n");

    /* Reset terminal output color to normal. */
    printf(RESET);
}
#endif
