#include "gtest/gtest.h"

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
