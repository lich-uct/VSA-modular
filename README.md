# numlib

A tiny C library of integer range and array-statistics helpers, built with CMake and tested with [Unity](https://github.com/ThrowTheSwitch/Unity).

## What's in it

| File | Functions | Tested? |
| --- | --- | --- |
| `src/range.c` | `min_int`, `max_int` | Yes |
| `src/stats.c` | `sum_int_array`, `average_int_array` | No |

All four functions are declared in the single public header, `include/numlib.h`.

```c
#include "numlib.h"

int smaller = min_int(3, 7);              // 3
int larger  = max_int(3, 7);               // 7

int values[] = {2, 4, 6, 8};
int total    = sum_int_array(values, 4);    // 20
double avg   = average_int_array(values, 4); // 5.0
```

## Project layout

```
numlib/
├── CMakeLists.txt
├── include/
│   └── numlib.h
└── src/
    ├── range.c
    ├── stats.c
    └── tests/
        └── test_numlib.c
```

- `include/` holds the public interface — the only header consumers need.
- `src/` holds the implementation. `target_include_directories(numlib PUBLIC include)` in `CMakeLists.txt` exposes `include/` to anything that links against the `numlib` target, so no relative paths are needed from the outside.
- `src/tests/` holds the test suite, built as its own executable and registered with CTest.

## Building

```sh
cmake -S . -B build
cmake --build build
```

This builds the `numlib` static library and the `numlib_tests` executable. [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html) downloads Unity automatically on first configure — no system install required.

## Running the tests

```sh
ctest --test-dir build --output-on-failure
```

The current suite covers `range.c` only:

- `test_min_int_returns_the_smaller_value`
- `test_min_int_returns_either_value_when_equal`
- `test_max_int_returns_the_larger_value`

`stats.c` (`sum_int_array` / `average_int_array`) ships without tests for now — a deliberate gap, left as an exercise.

## Using numlib in another CMake project

```cmake
add_subdirectory(path/to/numlib)

add_executable(app main.c)
target_link_libraries(app PRIVATE numlib)
```

Any file in `app` can then `#include "numlib.h"` directly, with no relative path to guess.
