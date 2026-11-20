#ifndef NUMLIB_H
#define NUMLIB_H

#include <stddef.h>

int min_int(int a, int b);
int max_int(int a, int b);

int sum_int_array(const int *values, size_t count);
double average_int_array(const int *values, size_t count);

#endif
