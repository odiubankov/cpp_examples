#include <cstddef>

#include "gtest/gtest.h"

namespace {

TEST(byte, test) {
    std::byte b1{42};
    ASSERT_EQ(std::to_integer<int>(b1), 42);
    ASSERT_TRUE(std::to_integer<bool>(b1));

    std::byte b2{0b0000'0001};
    ASSERT_EQ(std::to_integer<int>(b2), 1);
    ASSERT_TRUE(std::to_integer<bool>(b2));

    std::byte b3{0b0000'0000};
    ASSERT_EQ(std::to_integer<int>(b3), 0);
    ASSERT_FALSE(std::to_integer<bool>(b3));
}

}  // namespace
