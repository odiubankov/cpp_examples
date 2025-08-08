#include "gtest/gtest.h"

// C++17 introduces the ability to initialize variables in an if statement,
// which can help avoid scope pollution.

namespace {

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

}  // namespace
