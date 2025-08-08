#include "gtest/gtest.h"

// C++17 introduces the [[maybe_unused]] attribute, which can be used to
// indicate that a variable or function parameter may not be used.

namespace {

bool foo([[maybe_unused]] int bar) { return true; }

TEST(maybe_unused_attr, test_func_param) { ASSERT_TRUE(foo(10)); }

}  // namespace
