#include <functional>
#include <iostream>

#include "gtest/gtest.h"

void foo() {}
void bar() noexcept {}

TEST(noexcept_in_type, test) {
  void (*function_pointer)() noexcept = nullptr;
  // function_pointer = foo; doesn't compile
  function_pointer = bar;
  const auto res = std::is_same<decltype(foo), decltype(bar)>::value;
  ASSERT_FALSE(res);
}
