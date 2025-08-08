#include <string>

#include "gtest/gtest.h"

// C++17 introduces if constexpr, which allows compile-time branching based on
// type traits or constant expressions. This can be used to create functions
// that behave differently based on the type of their arguments, without the
// need for template specialization or SFINAE.

namespace {

template <typename T>
std::string asString(T x) {
  if constexpr (std::is_same_v<T, std::string>) {
    return x;
  } else if constexpr (std::is_arithmetic_v<T>) {
    return std::to_string(x);
  } else {
    return std::string(x);
  }
}

TEST(if_constexpr, test) {
  ASSERT_EQ(asString(42), "42");
  ASSERT_EQ(asString(std::string("Hello")), "Hello");
  ASSERT_EQ(asString("Hello"), "Hello");
}

}  // namespace
