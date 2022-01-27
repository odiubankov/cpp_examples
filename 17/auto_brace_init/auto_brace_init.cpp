#include <type_traits>

#include "gtest/gtest.h"

TEST(auto_brace_init, test) {
  auto foo{10};
  const auto res = std::is_same<decltype(foo), int>::value;
  ASSERT_TRUE(res);
}
