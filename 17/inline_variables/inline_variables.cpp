#include "gtest/gtest.h"

class TestClass {
 public:
  inline static const std::string defined_in_class{"defined_in_class"};
  // this is not allowed without inline
  // static const std::string defined_in_class{"defined_in_class"};
};

// this is not needed with inline declaration
// const std::string TestClass::defined_in_class{"defined_in_class"};

TEST(inline_variables, test) {
  ASSERT_EQ(TestClass::defined_in_class, "defined_in_class");
}
