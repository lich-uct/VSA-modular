# numlib

A tiny C library of integer range and array-statistics helpers, packaged as a reusable CMake library and consumed by a small sample app.

## What's in it

| File | Functions |
| --- | --- |
| `src/range.c` | `min_int`, `max_int` |
| `src/stats.c` | `sum_int_array`, `average_int_array` |

All four functions are declared in the single public header, `include/numlib.h`. `average_int_array` is built by calling `sum_int_array` — a small example of functions composing into bigger ones.

```c
#include "numlib.h"

int smaller = min_int(3, 7);               // 3
int larger  = max_int(3, 7);                // 7

int values[] = {2, 4, 6, 8};
int total    = sum_int_array(values, 4);     // 20
double avg   = average_int_array(values, 4); // 5.0
```

## Project layout

```
numlib/
├── CMakeLists.txt
├── include/
│   └── numlib.h
├── src/
│   ├── range.c
│   └── stats.c
└── app/
    └── main.c
```

- `include/` holds the public interface — the only header a caller needs. The source files only ever declare what they define; the header is the single source of truth for the signatures.
- `src/` holds the implementation. `target_include_directories(numlib PUBLIC include)` in `CMakeLists.txt` exposes `include/` to anything that links against the `numlib` target, so no relative path to the header has to be spelled out from the outside.
- `app/` is a small consumer: `main.c` includes `numlib.h` and links against the `numlib` target to print a few results.

## Building and running

```sh
cmake -S . -B build
cmake --build build
./build/app
```

This builds `numlib` as a static library and `app` as an executable linked against it. Expected output:

```
min(3, 7) = 3
max(3, 7) = 7
average = 5.00
```

## Using numlib in another CMake project

```cmake
add_subdirectory(path/to/numlib)

add_executable(your_app main.c)
target_link_libraries(your_app PRIVATE numlib)
```

Any file in `your_app` can then `#include "numlib.h"` directly — CMake wires up the include path and the compiled code together.
