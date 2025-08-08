#include <iostream>

#include "gtest/gtest.h"

// C++17 introduces the [[fallthrough]] attribute, which can be used to indicate that a case in a switch statement intentionally falls through to the next case.

namespace {

bool foo(int bar) {
  switch (bar) {
    case 10:
      std::cout << "bar " << bar << std::endl;
      [[fallthrough]];
    case 20:
      return true;
      break;
  }

  return false;
}

TEST(fallthrough_attr, test) {
  ASSERT_TRUE(foo(10));
  ASSERT_TRUE(foo(20));
  ASSERT_FALSE(foo(30));
}

}  // namespace
