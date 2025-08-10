#include "gtest/gtest.h"

// C++17 allows the use of `auto` as a non-type template parameter.
// This feature enables more flexible and type-safe template programming.

namespace {

template <auto N>
struct S {
  static constexpr auto n_ = N;
};

template <decltype(auto) N>
struct K {
  decltype(auto) get_n() const { return N; }
};

TEST(auto_as_template_args, test) {
  S<42> s42;  // Using an integer as a non-type template parameter
  S<'M'> sM;  // Using a character as a non-type template parameter
  ASSERT_EQ(s42.n_, 42);
  ASSERT_EQ(sM.n_, 'M');
}

TEST(decltype_auto_as_tamplate_arg, test) {
  static int a = 10;
  K<(a)> kA;
  a = 11;
  ASSERT_EQ(kA.get_n(), 11);
}

}  // namespace
