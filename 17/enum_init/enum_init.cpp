#include "gtest/gtest.h"

enum class Fruit : int {
  Banana = 10,
  Apple = 20,
  Orange = 30,
  Kiwi = 40,
  Mandarine = 50
};

TEST(enum_init, test) {
  const Fruit fruit{50};
  ASSERT_EQ(fruit, Fruit::Mandarine);
}
