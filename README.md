# Lighthouse
A lightweight famework for testing C programs from the command line.

## TL;DR

1. Clone this repository, then copy `lighthouse.h` file into the folder containing your project
2. Create test file
3. `#include "lighthouse.h"` at the top
4. Write your tests to return `failed()` if a failure condition is met, or `success()` otherwise. Test functions must return `failed()` or `success()`
5. Call your test within `main()` by passing its function pointer to `run()`: `run(&test_function)`
6. To print the results, call `print_test_summary()` at the end
7. Compile with `gcc -rdynamic testfile.c -o test`
8. Run with `./test`
9. Smile, because now testing is easier!

## Example

Here's an example of how to use Lighthouse. An extended version of this file is part of the repo, so you can clone it to your machine and run it locally using steps 8 and 9 above.

    #include <stdio.h>

    /* This adds Lighthouse to your project. */
    #include "lighthouse.h"

    /*********************************** IMPLEMENTATION *************************/

    /* This function takes an integer indicating the day of the week and returns 1
     * (true) or 0 (false) indicating whether or not it is the weekend. */
    int is_weekend(int day) {
        if ((day > 0) || (day < 7)) {
            return 0;
        } else {
            return 1;
        }
    }

    /************************************ TESTS ******************************/

    int test_is_weekend_with_weekday() {    // Test return type must be int
        if (is_weekend(3) != 0) {
            return failed();                // Return failed() on failure condition
        } else {
            return success();               // Test must return failed() or success()
        }
    }

    int test_is_weekend_with_monday() {
        if (is_weekend(0) != 0) {
            return failed();
        } else {
            return success();
        }
    }

    int test_is_weekend_with_negative_number() {
        if (is_weekend(-1) != -1) {
            return failed();
        } else {
            return success();
        }
    }

    /*********************************** RUN TESTS ****************************/
    int main(){

        run(&test_is_weekend_with_weekday);
        run(&test_is_weekend_with_monday);
        run(&test_is_weekend_with_negative_number);

        print_testing_summary();

        return 0;
    }

When run, this file produces the following output. Failed tests will display in red when run from the terminal.

    TEST PASSED: test_is_weekend_with_weekday

    TEST PASSED: test_is_weekend_with_monday

    TEST FAILED: test_is_weekend_with_negative_number


    ******************** TESTING SUMMARY ****************

    Ran 3 tests: Passed: 2 | Failed: 1

    *****************************************************


## The Fine Print

Lighthouse is machine dependent at the moment; it only works on Linux. Efforts may be made in the future to make it more portable.


## API Reference

#### `void run(int (*test_func)(void))`

For each test function you'd like to run, call `run` with a pointer to the test function. Run will execute your test function and keep track of the total number of tests run.


#### `int failed(void)`

If you reach a failure condition (i.e., you called the function you're testing and it didn't do what it was supposed to) in your test function, `return failed()`. `failed` will keep track of how many tests have failed, and print the results of your test to the terminal.


#### `int success(void)`

If none of the failure conditions in your test method are met, `return success()`. `success` keeps track of the number of tests passed, and prints the results of your test to the terminal.


#### `void print_result_summary(void)`

Call `print_result_summary()` at the end of `main()` inside your test file. It will print a color-coded summary of your test results. The summary includes number of tests run, number of tests passed, and number of tests failed. The summary will print in red if any tests fail or green if all tests pass.


