#include "unity.h"          // test macros + runner
#include "numlib.h"         // the code under test

void setUp(void) {}      // runs before each test (unused here)
void tearDown(void) {}   // runs after each test (unused here)

void test_min_int_returns_the_smaller_value(void) {
  // Arrange
  int a = 3;
  int b = 7;

  // Act
  int result = min_int(a, b);

  // Assert
  TEST_ASSERT_EQUAL_INT(3, result);
}

// Shorter tests skip the comments once the pattern is familiar
void test_min_int_returns_either_value_when_equal(void) {
  TEST_ASSERT_EQUAL_INT(5, min_int(5, 5));
}

void test_max_int_returns_the_larger_value(void) {
  TEST_ASSERT_EQUAL_INT(7, max_int(3, 7));
}

int main(void) {
  UNITY_BEGIN();  // start the run
  RUN_TEST(test_min_int_returns_the_smaller_value);
  RUN_TEST(test_min_int_returns_either_value_when_equal);
  RUN_TEST(test_max_int_returns_the_larger_value);
  return UNITY_END();  // tally results; non-zero exit if anything failed
}
