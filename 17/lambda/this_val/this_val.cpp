#include "gtest/gtest.h"

// C++17 allows lambdas to capture `this` by value, which can be useful for accessing member variables.

namespace {

class A {
 public:
  int foo_ = 10;
  decltype(auto) get_lambda() const {
    return [*this]() { return foo_; };
  }

  void set_foo(int value) {
    foo_ = value;
  }

};

TEST(lambda_this_val, test) {
  A a;
  const auto bar = a.get_lambda();
  a.set_foo(20);
  ASSERT_EQ(bar(), 10);
}

}  // namespace
