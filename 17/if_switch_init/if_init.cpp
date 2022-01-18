#include "gtest/gtest.h"

bool true_case() { return true; }

TEST(if_init, test) {
  bool bar = true;
  if (const auto foo = true_case(); foo) {
    bar = false;
  } else {
    bar = foo;
  }
  const auto foo = false;
  ASSERT_FALSE(bar);
  ASSERT_FALSE(foo);
}
