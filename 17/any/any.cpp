#include <any>
#include <string>

#include "gtest/gtest.h"

namespace {

TEST(any, test) {
    std::any a = 1;
    a = 3.14;
    a = std::string{"Hello, World!"};
    ASSERT_EQ(a.type(), typeid(std::string));
    ASSERT_EQ(std::any_cast<std::string>(a), "Hello, World!");
    a.reset();
    ASSERT_FALSE(a.has_value());
}

}  // namespace
