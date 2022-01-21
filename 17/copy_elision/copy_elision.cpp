#include "gtest/gtest.h"

class A {
 public:
  A() = default;
  ~A() = default;

  A(const A&) = delete;
  A(A&&) = delete;
  A& operator=(const A&) = delete;
  A& operator=(A&&) = delete;

  int foo = 10;
};

A create_a() { return A{}; }

void pass_a(A a) {}

TEST(copy_elision, test) {
  A a = create_a();
  pass_a(A{});
  ASSERT_EQ(a.foo, 10);
}
