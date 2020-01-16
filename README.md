# Lighthouse
A lightweight famework for testing C programs from the command line.

## TL;DR

1. Clone this repository, then copy `lighthouse.h` file into the folder containing your project
2. Create test file
3. `#include "lighthouse.h"` at the top
4. Write your tests using `assert(condition)`
5. Call your test within `main()` by passing it to `run()`: `run(test_function)`
6. To print the results, call `print_testing_summary()` at the end
7. Compile with `gcc testfile.c -o test`
8. Run with `./test`
9. Smile, because now testing is easier!

## Example

Here's an example of how to use Lighthouse. An extended version of this file is part of the repo, so you can clone it to your machine and run it locally using steps 8 and 9 above.

```c
#include <stdio.h>

/* This adds Lighthouse to your project. */
#include "lighthouse.h"

/*********************************** IMPLEMENTATION *************************/

/* This function takes an integer indicating the day of the week and returns 1
 * (true) or 0 (false) indicating whether or not it is the weekend. */
int is_weekend(int day) {
    if ((day > 0) && (day < 5)) {
        return 0;
    } else {
        return 1;
    }
}

/************************************ TESTS ******************************/

int test_is_weekend_with_weekday() {    // Test return type must be int
    assert(is_weekend(3) == 0);         // Add your test conditions
}

int test_is_weekend_with_monday() {
    assert(is_weekend(0) == 0);
}

int test_is_weekend_with_negative_number() {
    assert(is_weekend(-1) == -1);
}

/*********************************** RUN TESTS ****************************/
int main(){

    run(test_is_weekend_with_weekday);
    run(test_is_weekend_with_monday);
    run(test_is_weekend_with_negative_number);

    print_testing_summary();

    return 0;
}
```

When run, this file produces the following output. Failed tests will display in red when run from the terminal.

    TEST FAILED: test_is_weekend_with_negative_number
        Assertion Error: line 29

    ******************** TESTING SUMMARY ****************

    Ran 3 tests: Passed: 2 | Failed: 1

    *****************************************************


## API Reference

#### `run(func_name)`

For each test function you'd like to run, call `run` with the name of the test function. Run will execute your test function and keep track of the total number of tests run.

#### `assert(condition)`

Pass a conditional statement to `assert` to indicate the intended behavior of your functions. If the condition fails, that will cause the test to fail. It will print an assertion error message to the console.


#### `void print_testing_summary(void)`

Call `print_testing_summary()` at the end of `main()` inside your test file. It will print a color-coded summary of your test results. The summary includes number of tests run, number of tests passed, and number of tests failed. The summary will print in red if any tests fail or green if all tests pass.


