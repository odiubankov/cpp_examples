#include "gtest/gtest.h"

// C++17 introduces nested namespaces, allowing for cleaner organization of code
// by grouping related namespaces together.

namespace {

namespace foo::bar {
bool f() { return true; }
}  // namespace foo::bar

TEST(nested_namespaces, test) { ASSERT_TRUE(foo::bar::f()); }

}  // namespace
