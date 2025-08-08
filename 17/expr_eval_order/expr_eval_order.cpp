#include "gtest/gtest.h"

namespace {

// C++17 introduces guaranteed evaluation order for expressions, which means
// that the order of evaluation of function arguments and sub-expressions is
// well-defined.

int foo(int& var) {
  ++var;
  return var;
}

int bar(int& var) {
  --var;
  return var;
}

TEST(expr_eval_order, test) {
  int var = 10;
  const int res = foo(var) * bar(var);
  ASSERT_EQ(res, 110);  // before defined order the answer could be 90
}

}  // namespace
