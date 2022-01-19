#include "gtest/gtest.h"

class ClassWithInlineVariable {
 public:
  inline static const std::string defined_in_class = "defined_in_class";
  // this is not allowed without inline
  // static const std::string defined_in_class{"defined_in_class"};
};

// this is not needed with inline declaration
// const std::string
// ClassWithInlineVariable::defined_in_class{"defined_in_class"};

TEST(inline_variables, explicit_inline) {
  ASSERT_EQ(ClassWithInlineVariable::defined_in_class, "defined_in_class");
}

class ClassWithImplicitlyInlineVariable {
 public:
  static constexpr int value = 1;
};

// this definition is still valid, but deprecated and can be omitted
constexpr int ClassWithImplicitlyInlineVariable::value;

TEST(inline_variables, implicit_inline) {
  ASSERT_EQ(ClassWithImplicitlyInlineVariable::value, 1);
}
