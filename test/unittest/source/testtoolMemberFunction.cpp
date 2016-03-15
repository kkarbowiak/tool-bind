#include "catch/catch.hpp"

#include "toolMemberFunction.h"


namespace
{
    class C
    {
        public:
            double function0();
            double function0c() const;
            double function1(int i);
            double function1c(int i) const;
            double function2(int i, float f);
            double function2c(int i, float f) const;
            double function3(int i, float f, double d);
            double function3c(int i, float f, double d) const;
            double function4(int i, float f, double d, double d2);
            double function4c(int i, float f, double d, double d2) const;
            double function5(int i, float f, double d, double d2, int i2);
            double function5c(int i, float f, double d, double d2, int i2) const;
    };
}

////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests nullary-member-function wrapper", "[tool][MemberFunction][nullary]")
{
    SECTION("Tests non-const version")
    {
        tool::mem_fn0<double, C> fn(&C::function0);

        C obj;
        REQUIRE(obj.function0() == fn.execute(&obj));
    }

    SECTION("Tests const version")
    {
        tool::mem_cfn0<double, C> fn(&C::function0c);

        const C obj;
        REQUIRE(obj.function0c() == fn.execute(&obj));
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests unary-member-function wrapper", "[tool][MemberFunction][unary]")
{
    const int i = 7;

    SECTION("Tests non-const version")
    {
        tool::mem_fn1<double, C, int> fn(&C::function1);

        C obj;
        REQUIRE(obj.function1(i) == fn.execute(&obj, i));
    }

    SECTION("Tests const version")
    {
        tool::mem_cfn1<double, C, int> fn(&C::function1c);

        const C obj;
        REQUIRE(obj.function1c(i) == fn.execute(&obj, i));
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binary-member-function wrapper", "[tool][MemberFunction][binary]")
{
    const int i = 7;
    const float f = 2.718f;

    SECTION("Tests non-const version")
    {
        tool::mem_fn2<double, C, int, float> fn(&C::function2);

        C obj;
        REQUIRE(obj.function2(i, f) == fn.execute(&obj, i, f));
    }

    SECTION("Tests const version")
    {
        tool::mem_cfn2<double, C, int, float> fn(&C::function2c);

        const C obj;
        REQUIRE(obj.function2c(i, f) == fn.execute(&obj, i, f));
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests ternary-member-function wrapper", "[tool][MemberFunction][ternary]")
{
    const int i = 7;
    const float f = 2.718f;
    const double d = 1.41;

    SECTION("Tests non-const version")
    {
        tool::mem_fn3<double, C, int, float, double> fn(&C::function3);

        C obj;
        REQUIRE(obj.function3(i, f, d) == fn.execute(&obj, i, f, d));
    }

    SECTION("Tests const version")
    {
        tool::mem_cfn3<double, C, int, float, double> fn(&C::function3c);

        const C obj;
        REQUIRE(obj.function3c(i, f, d) == fn.execute(&obj, i, f, d));
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests quaternary-member-function wrapper", "[tool][MemberFunction][quaternary]")
{
    const int i = 7;
    const float f = 2.718f;
    const double d = 1.41;
    const double d2 = 0.999;

    SECTION("Tests non-const version")
    {
        tool::mem_fn4<double, C, int, float, double, double> fn(&C::function4);

        C obj;
        REQUIRE(obj.function4(i, f, d, d2) == fn.execute(&obj, i, f, d, d2));
    }

    SECTION("Tests const version")
    {
        tool::mem_cfn4<double, C, int, float, double, double> fn(&C::function4c);

        const C obj;
        REQUIRE(obj.function4c(i, f, d, d2) == fn.execute(&obj, i, f, d, d2));
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests quinary-member-function wrapper", "[tool][MemberFunction][quinary]")
{
    const int i = 7;
    const float f = 2.718f;
    const double d = 1.41;
    const double d2 = 0.999;
    const int i2 = 3;

    SECTION("Tests non-const version")
    {
        tool::mem_fn5<double, C, int, float, double, double, int> fn(&C::function5);

        C obj;
        REQUIRE(obj.function5(i, f, d, d2, i2) == fn.execute(&obj, i, f, d, d2, i2));
    }

    SECTION("Tests const version")
    {
        tool::mem_cfn5<double, C, int, float, double, double, int> fn(&C::function5c);

        const C obj;
        REQUIRE(obj.function5c(i, f, d, d2, i2) == fn.execute(&obj, i, f, d, d2, i2));
    }
}
////////////////////////////////////////////////////////////////////////////////

namespace
{
////////////////////////////////////////////////////////////////////////////////
double C::function0()
{
    return 3.14;
}
////////////////////////////////////////////////////////////////////////////////
double C::function0c() const
{
    return 3.14 + 1;
}
////////////////////////////////////////////////////////////////////////////////
double C::function1(int i)
{
    return 3.14 * i;
}
////////////////////////////////////////////////////////////////////////////////
double C::function1c(int i) const
{
    return 3.14 * i + 1;
}
////////////////////////////////////////////////////////////////////////////////
double C::function2(int i, float f)
{
    return 3.14 * i / f;
}
////////////////////////////////////////////////////////////////////////////////
double C::function2c(int i, float f) const
{
    return 3.14 * i / f + 1;
}
////////////////////////////////////////////////////////////////////////////////
double C::function3(int i, float f, double d)
{
    return 3.14 * i / f * d;
}
////////////////////////////////////////////////////////////////////////////////
double C::function3c(int i, float f, double d) const
{
    return 3.14 * i / f * d + 1;
}
////////////////////////////////////////////////////////////////////////////////
double C::function4(int i, float f, double d, double d2)
{
    return 3.14 * i / f * d + d2;
}
////////////////////////////////////////////////////////////////////////////////
double C::function4c(int i, float f, double d, double d2) const
{
    return 3.14 * i / f * d + d2 + 1;
}
////////////////////////////////////////////////////////////////////////////////
double C::function5(int i, float f, double d, double d2, int i2)
{
    return 3.14 * i / f * d + d2 / i2;
}
////////////////////////////////////////////////////////////////////////////////
double C::function5c(int i, float f, double d, double d2, int i2) const
{
    return 3.14 * i / f * d + d2 / i2 + 1;
}
////////////////////////////////////////////////////////////////////////////////
}
