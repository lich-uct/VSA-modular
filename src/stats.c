#include "numlib.h"

int sum_int_array(const int *values, size_t count) {
  int total = 0;
  for (size_t i = 0; i < count; i++) {
    total += values[i];
  }
  return total;
}

double average_int_array(const int *values, size_t count) {
  if (count == 0) {
    return 0.0;
  }
  return (double)sum_int_array(values, count) / count;
}
