#include "gtest/gtest.h"

// Two examples of elision below:
// 1. Named return value optimization (NRVO) - the compiler optimizes the return
//    of a local object by constructing it directly in the caller's context.
// 2. Copy elision - the compiler optimizes the copy of an object by eliminating
//    the copy operation entirely, allowing the object to be constructed directly

namespace {

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

}
