#include "gtest/gtest.h"

class A {
 public:
  int foo_ = 10;
  decltype(auto) get_lambda() const {
    return [*this]() { return foo_; };
  }
};

TEST(lambda_this_val, test) {
  const auto bar = A{}.get_lambda();
  ASSERT_EQ(bar(), 10);
}
