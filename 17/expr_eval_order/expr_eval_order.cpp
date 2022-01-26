#include "gtest/gtest.h"

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
