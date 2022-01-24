#include "gtest/gtest.h"

bool foo([[maybe_unused]] int bar) { return true; }

TEST(maybe_unused_attr, test_func_param) { ASSERT_TRUE(foo(10)); }
