#include "catch/catch.hpp"

#include "toolFunction.h"


namespace
{
    double function0();
    double function1(int i);
    double function2(int i, float f);
    double function3(int i, float f, double d);
    double function4(int i, float f, double d, double d2);
    double function5(int i, float f, double d, double d2, int i2);
}

////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests nullary-function wrapper", "[tool][Function][nullary]")
{
    tool::fn0<double> fn(&function0);

    REQUIRE(function0() == fn.execute());
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests unary-function wrapper", "[tool][Function][unary]")
{
    tool::fn1<double, int> fn(&function1);

    const int i = 7;

    REQUIRE(function1(i) == fn.execute(i));
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binary-function wrapper", "[tool][Function][binary]")
{
    tool::fn2<double, int, float> fn(&function2);

    const int i = 7;
    const float f = 2.718f;

    REQUIRE(function2(i, f) == fn.execute(i, f));
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests ternary-function wrapper", "[tool][Function][ternary]")
{
    tool::fn3<double, int, float, double> fn(&function3);

    const int i = 7;
    const float f = 2.718f;
    const double d = 1.41;

    REQUIRE(function3(i, f, d) == fn.execute(i, f, d));
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests quaternary-function wrapper", "[tool][Function][quaternary]")
{
    tool::fn4<double, int, float, double, double> fn(&function4);

    const int i = 7;
    const float f = 2.718f;
    const double d = 1.41;
    const double d2 = 0.999;

    REQUIRE(function4(i, f, d, d2) == fn.execute(i, f, d, d2));
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests quinary-function wrapper", "[tool][Function][quinary]")
{
    tool::fn5<double, int, float, double, double, int> fn(&function5);

    const int i = 7;
    const float f = 2.718f;
    const double d = 1.41;
    const double d2 = 0.999;
    const int i2 = 3;

    REQUIRE(function5(i, f, d, d2, i2) == fn.execute(i, f, d, d2, i2));
}
////////////////////////////////////////////////////////////////////////////////

namespace
{
////////////////////////////////////////////////////////////////////////////////
double function0()
{
    return 3.14;
}
////////////////////////////////////////////////////////////////////////////////
double function1(int i)
{
    return 3.14 * i;
}
////////////////////////////////////////////////////////////////////////////////
double function2(int i, float f)
{
    return 3.14 * i / f;
}
////////////////////////////////////////////////////////////////////////////////
double function3(int i, float f, double d)
{
    return 3.14 * i / f * d;
}
////////////////////////////////////////////////////////////////////////////////
double function4(int i, float f, double d, double d2)
{
    return 3.14 * i / f * d + d2;
}
////////////////////////////////////////////////////////////////////////////////
double function5(int i, float f, double d, double d2, int i2)
{
    return 3.14 * i / f * d + d2 / i2;
}
////////////////////////////////////////////////////////////////////////////////
}
