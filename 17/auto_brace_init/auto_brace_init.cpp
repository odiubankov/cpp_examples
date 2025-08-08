#include <type_traits>

#include "gtest/gtest.h"

// C++17 adds support for auto brace initialization, allowing the use of braces
// to initialize variables with type deduction.

namespace {

TEST(auto_brace_init, test) {
  auto foo{10};
  const auto res = std::is_same<decltype(foo), int>::value;
  ASSERT_TRUE(res);
}

}  // namespace
