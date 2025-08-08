#include <array>

#include "gtest/gtest.h"

// C++17 introduces constexpr lambdas, allowing the use of lambdas in constant expressions.

namespace {

TEST(constexpr_lambda, test) {
  const auto square_size = [](std::size_t s) { return s * s; };
  std::array<int, square_size(2)> foo;
  ASSERT_EQ(foo.size(), 4);
}

}
