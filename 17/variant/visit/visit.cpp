#include <variant>
#include <string>

#include "gtest/gtest.h"

namespace {

struct Fluid { };
struct LightItem { };
struct HeavyItem { };
struct FragileItem { };

struct VisitPackage {
    std::string operator()(Fluid& )       { return "fluid"; }
    std::string operator()(LightItem& )   { return "light"; }
    std::string operator()(HeavyItem& )   { return "heavy"; }
    std::string operator()(FragileItem& ) { return "fragile"; }
};

TEST(variant, visit) {
    using Package = std::variant<Fluid, LightItem, HeavyItem, FragileItem>;

    Package p1 = Fluid{};
    Package p2 = LightItem{};
    Package p3 = HeavyItem{};
    Package p4 = FragileItem{};

    VisitPackage visitor;

    ASSERT_EQ(std::visit(visitor, p1), "fluid");
    ASSERT_EQ(std::visit(visitor, p2), "light");
    ASSERT_EQ(std::visit(visitor, p3), "heavy");
    ASSERT_EQ(std::visit(visitor, p4), "fragile");
}

} // namespace
