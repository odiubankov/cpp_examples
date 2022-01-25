#include <iostream>

#include "gtest/gtest.h"

namespace foo::bar {
bool f() { return true; }
}  // namespace foo::bar

TEST(nested_namespaces, test) { ASSERT_TRUE(foo::bar::f()); }
