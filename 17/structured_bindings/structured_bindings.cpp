#include <array>

#include "gtest/gtest.h"

// C++17 introduces structured bindings, which allow unpacking of class members into variables.

namespace {

// Create structured binding to struct members
// use assignment initialization
TEST(structured_bindings, structure) {
  struct Point {
    int x;
    int y;
  };

  Point p = {1, 2};

  auto [x_coord, y_coord] = p;

  ASSERT_EQ(x_coord, 1);
  ASSERT_EQ(y_coord, 2);
}

// Create structured binding to array elements
TEST(structured_bindings, array) {
  std::array<int, 3> foo{0, 1, 2};
  auto& [el0, el1, el2] = foo;
  el1 = 5;
  ASSERT_EQ(foo.at(1), 5);
}

// Init structured binding using brace initialization
TEST(structured_bindings, brace_init) {
  struct Point {
    int x;
    int y;
  };

  Point p{1, 2};

  auto [x_coord, y_coord]{p};

  ASSERT_EQ(x_coord, 1);
  ASSERT_EQ(y_coord, 2);
}

// Init structured binding using parenthesis constructor
TEST(structured_bindings, parenthesis_init) {
  struct Point {
    int x;
    int y;
  };

  Point p{1, 2};

  auto [x_coord, y_coord](p);

  ASSERT_EQ(x_coord, 1);
  ASSERT_EQ(y_coord, 2);
}

// Check the underlying type of the binding
// It shows that there is an entry that is created and
// actual bindings are members of that entry. If refernce is used
// the entry itself is a reference and not its members
TEST(structured_binding, underlying_type) {
  struct TypeWithValues {
    TypeWithValues(std::pair<int, int> int_pair)
        : first{int_pair.first}, second{int_pair.second} {}

    int first;
    int second;
  };

  struct TypeWithReferences {
    TypeWithReferences(std::pair<int, int>& int_pair)
        : first{int_pair.first}, second{int_pair.second} {}
    int& first;
    int& second;
  };

  std::pair<int, int> int_pair{1, 2};
  TypeWithValues type_with_values{int_pair};
  TypeWithReferences type_with_references{int_pair};

  auto& [first, second] = int_pair;
  ASSERT_FALSE((std::is_same<decltype(type_with_references.first),
                             decltype(first)>::value));
  ASSERT_TRUE(
      (std::is_same<decltype(type_with_values.first), decltype(first)>::value));
}

}
