#include "gtest/gtest.h"

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
