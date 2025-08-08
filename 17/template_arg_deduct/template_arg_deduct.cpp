#include <vector>

#include "gtest/gtest.h"

// C++17 introduces template argument deduction for class templates, which allows the compiler to deduce template arguments from constructor arguments.

namespace {

TEST(template_arg_deduct, test) {
  std::vector foo{1, 2, 3};
  const auto res =
      std::is_same<std::decay<decltype(foo.at(0))>::type, int>::value;
  ASSERT_TRUE(res);
}

}
