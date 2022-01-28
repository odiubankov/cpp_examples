#include <vector>

#include "gtest/gtest.h"

TEST(template_arg_deduct, test) {
  std::vector foo{1, 2, 3};
  const auto res =
      std::is_same<std::decay<decltype(foo.at(0))>::type, int>::value;
  ASSERT_TRUE(res);
}
