#include "gtest/gtest.h"

// C++17 introduces the [[nodiscard]] attribute, which can be used to indicate that a function's return value should not be ignored.

namespace {

[[nodiscard]] bool foo() { return true; }

TEST(attribute_nodiscard, function_test) {
  foo();  // this will issue a warning [-Wunused-result]
  ASSERT_TRUE(foo());
}

struct [[nodiscard]] StructWithNoDiscard {
  bool bar = true;
};

StructWithNoDiscard get_struct() { return StructWithNoDiscard{}; }

TEST(attribute_nodiscard, struct_test) {
  get_struct();  // this will issue a warning [-Wunused-result]
  ASSERT_TRUE(get_struct().bar);
}

}
