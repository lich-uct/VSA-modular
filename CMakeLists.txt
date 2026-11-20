cmake_minimum_required(VERSION 3.14)
project(numlib C)

# Library under test (stats.c has no tests yet)
add_library(numlib src/range.c src/stats.c)
target_include_directories(numlib PUBLIC include)

# Pull in Unity, a small C testing framework
include(FetchContent)
FetchContent_Declare(
  unity
  URL https://github.com/ThrowTheSwitch/Unity/archive/refs/tags/v2.6.0.zip
)
FetchContent_MakeAvailable(unity)

# Test executable, linked against the library and Unity
add_executable(numlib_tests src/tests/test_numlib.c)
target_link_libraries(numlib_tests PRIVATE numlib unity)

# Register the executable with CTest
enable_testing()
add_test(NAME numlib_tests COMMAND numlib_tests)
