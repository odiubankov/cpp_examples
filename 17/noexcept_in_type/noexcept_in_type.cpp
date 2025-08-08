#include <functional>
#include <iostream>

#include "gtest/gtest.h"

// C++17 introduces the noexcept in type specifiers, which can be used to
// indicate that a function pointer or reference is noexcept.

namespace {

void foo() {}
void bar() noexcept {}

TEST(noexcept_in_type, test) {
  void (*function_pointer)() noexcept = nullptr;
  // function_pointer = foo; doesn't compile
  function_pointer = bar;
  const auto res = std::is_same<decltype(foo), decltype(bar)>::value;
  ASSERT_FALSE(res);
}

}  // namespace
