#include <string_view>

#include "gtest/gtest.h"

namespace {

TEST(string_view, test) {
  std::string_view sv1 = "Hello, World!";
  std::string_view sv2 = sv1.substr(7, 5); // "World"
  ASSERT_EQ(sv2, "World");
  ASSERT_TRUE(sv1.data());
  ASSERT_EQ(sv1.data(), sv2.data() - 7);
}

} // namespace
