cmake_minimum_required(VERSION 3.14)
project(numlib C)

# The library: functions + their public header
add_library(numlib
  src/range.c
  src/stats.c
)
target_include_directories(numlib PUBLIC include)

# An executable that consumes the library
add_executable(app app/main.c)
target_link_libraries(app PRIVATE numlib)
