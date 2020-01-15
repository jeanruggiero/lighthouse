# Lighhouse
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

Here's an example of how to use Lighthouse. This file is part of this repo, so you can clone it to your machine and run it locally using steps 8 and 9 above.


## The Fine Print

Lighthouse is machine dependent at the moment; it only works on Linux. Efforts may be made in the future to make it more portable.


## API Reference

`void run(int (*test_func)(void))`

For each test function you'd like to run, call
