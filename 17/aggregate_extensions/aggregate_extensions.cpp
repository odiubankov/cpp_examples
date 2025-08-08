#include "gtest/gtest.h"

// It was not possible to use aggregate initialization until C++17 if class has
// a base class.

namespace {

struct A {
  int a_ = 0;
};

struct B : A {
  int b_ = 0;
};

TEST(aggregate_extension, extension_in_construct) {
  B b{{}, 2};
  ASSERT_EQ(0, b.a_);
  ASSERT_EQ(2, b.b_);
}

TEST(aggregate_extension, no_extension_in_construct) {
  B b{1, 2};
  ASSERT_EQ(1, b.a_);
  ASSERT_EQ(2, b.b_);
}

}  // namespace
