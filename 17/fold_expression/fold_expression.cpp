#include "gtest/gtest.h"

// C++17 introduces fold expressions, which allow for more concise and
// readable code when dealing with variadic templates. They enable the
// application of binary operators over parameter packs.

namespace {

TEST(fold_expression, test) {
  auto sum = [](auto... args) {
    return (args + ...);  // Fold expression to sum all arguments
  };

  auto product = [](auto... args) {
    return (args * ...);  // Fold expression to multiply all arguments
  };

  ASSERT_EQ(sum(1, 2, 3, 4), 10);
  ASSERT_EQ(product(1, 2, 3, 4), 24);
}

}  // namespace
