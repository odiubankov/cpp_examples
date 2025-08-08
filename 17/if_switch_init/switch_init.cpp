#include "gtest/gtest.h"

// C++17 introduces the ability to initialize variables in a switch statement,
// which can help avoid scope pollution.

namespace {

int get_int() { return 5; }

TEST(switch_init, test) {
  int bar = 0;
  switch (const auto foo = get_int(); foo) {
    case 5:
      bar = 10;
      break;
  }
  const auto foo = 10;
  ASSERT_EQ(foo, bar);
}

}  // namespace
