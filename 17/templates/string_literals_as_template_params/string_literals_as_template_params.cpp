#include "gtest/gtest.h"

// C++17 allows string literals to be used as template parameters.
// This feature can be useful for compile-time string manipulation.

namespace {

template <const char* Str>
struct StringHolder {
  static constexpr const char* value = Str;
};

constexpr char hello[] = "Hello, World!";
constexpr char goodbye[] = "Goodbye, World!";

TEST(string_literals_as_template_args, test) {
  using HelloHolder = StringHolder<hello>;
  using GoodbyeHolder = StringHolder<goodbye>;

  ASSERT_STREQ(HelloHolder::value, "Hello, World!");
  ASSERT_STREQ(GoodbyeHolder::value, "Goodbye, World!");
}

}  // namespace
