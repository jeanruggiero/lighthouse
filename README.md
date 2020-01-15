# Lighhouse
A lightweight famework for testing C programs from the command line.

## TL;DR

1. Clone this repository, then copy `lighthouse.h` file into the folder containing your project
2. Create test file
3. `#include "lighthouse.h"` at the top
4. Write your tests to return `failed()` if a failure condition is met, or `success()` otherwise
5. Test functions must return `failed()` or `success()`
6. Call your test
