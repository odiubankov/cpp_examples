#include "gtest/gtest.h"

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
