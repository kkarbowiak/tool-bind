#include "catch/catch.hpp"

#include "toolBind.h"

#include <string>


namespace
{
    class FObjectBase
    {
        public:
            virtual ~FObjectBase() {}

            virtual std::string exec() const = 0;
    };

    template<class F>
    class FObject : public FObjectBase
    {
        public:
            explicit FObject(F const & f) : mF(f) {}
            virtual std::string exec() const { return mF(); }

        private:
            mutable F mF;
    };

    template<class F>
    FObject<F> keep(F const & f) { return FObject<F>(f); }
}

namespace
{
    std::string function0();
    std::string function1(std::string const & s1);
    std::string function2(std::string const & s1, std::string const & s2);
    std::string function3(std::string const & s1, std::string const & s2, std::string const & s3);
    std::string function4(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4);
    std::string function5(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4, std::string const & s5);
}

namespace
{
    class C
    {
        public:
            std::string function0();
            std::string function0c() const;
            std::string function1(std::string const & s1);
            std::string function1c(std::string const & s1) const;
            std::string function2(std::string const & s1, std::string const & s2);
            std::string function2c(std::string const & s1, std::string const & s2) const;
            std::string function3(std::string const & s1, std::string const & s2, std::string const & s3);
            std::string function3c(std::string const & s1, std::string const & s2, std::string const & s3) const;
            std::string function4(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4);
            std::string function4c(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4) const;
            std::string function5(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4, std::string const & s5);
            std::string function5c(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4, std::string const & s5) const;
    };
}

////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a nullary function", "[tool][Bind][nullary][function]")
{
    REQUIRE(function0() == tool::bind(&function0)());
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a unary function", "[tool][Bind][unary][function]")
{
    std::string s1 = "str1";
    std::string s11 = s1;

    FObjectBase const & fobj = keep(tool::bind(&function1, s1));

    s1 = "failed1";

    REQUIRE(function1(s11) == fobj.exec());
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a binary function", "[tool][Bind][binary][function]")
{
    std::string s1 = "str1";
    std::string s11 = s1;
    std::string s2 = "str2";
    std::string s22 = s2;

    FObjectBase const & fobj = keep(tool::bind(&function2, s1, s2));

    s1 = "failed1";
    s2 = "failed2";

    REQUIRE(function2(s11, s22) == fobj.exec());
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a ternary function", "[tool][Bind][ternary][function]")
{
    std::string s1 = "str1";
    std::string s11 = s1;
    std::string s2 = "str2";
    std::string s22 = s2;
    std::string s3 = "str3";
    std::string s33 = s3;

    FObjectBase const & fobj = keep(tool::bind(&function3, s1, s2, s3));

    s1 = "failed1";
    s2 = "failed2";
    s3 = "failed3";

    REQUIRE(function3(s11, s22, s33) == fobj.exec());
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a quaternary function", "[tool][Bind][quaternary][function]")
{
    std::string s1 = "str1";
    std::string s11 = s1;
    std::string s2 = "str2";
    std::string s22 = s2;
    std::string s3 = "str3";
    std::string s33 = s3;
    std::string s4 = "str4";
    std::string s44 = s4;

    FObjectBase const & fobj = keep(tool::bind(&function4, s1, s2, s3, s4));

    s1 = "failed1";
    s2 = "failed2";
    s3 = "failed3";
    s4 = "failed4";

    REQUIRE(function4(s11, s22, s33, s44) == fobj.exec());
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a quinary function", "[tool][Bind][quinary][function]")
{
    std::string s1 = "str1";
    std::string s11 = s1;
    std::string s2 = "str2";
    std::string s22 = s2;
    std::string s3 = "str3";
    std::string s33 = s3;
    std::string s4 = "str4";
    std::string s44 = s4;
    std::string s5 = "str5";
    std::string s55 = s5;

    FObjectBase const & fobj = keep(tool::bind(&function5, s1, s2, s3, s4, s5));

    s1 = "failed1";
    s2 = "failed2";
    s3 = "failed3";
    s4 = "failed4";
    s5 = "failed5";

    REQUIRE(function5(s11, s22, s33, s44, s55) == fobj.exec());
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a nullary member function", "[tool][Bind][nullary][member][function]")
{
    SECTION("Tests non-const version")
    {
        C obj;

        REQUIRE(obj.function0() == tool::bind(&C::function0, &obj)());
    }

    SECTION("Tests const version")
    {
        const C obj;

        REQUIRE(obj.function0c() == tool::bind(&C::function0c, &obj)());
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a unary member function", "[tool][Bind][unary][member][function]")
{
    SECTION("Tests non-const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function1, &obj, s1));

        s1 = "failed1";

        REQUIRE(obj.function1(s11) == fobj.exec());
    }

    SECTION("Tests const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        const C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function1c, &obj, s1));

        s1 = "failed1";

        REQUIRE(obj.function1c(s11) == fobj.exec());
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a binary member function", "[tool][Bind][binary][member][function]")
{
    SECTION("Tests non-const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        std::string s2 = "str2";
        std::string s22 = s2;
        C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function2, &obj, s1, s2));

        s1 = "failed1";
        s2 = "failed2";

        REQUIRE(obj.function2(s11, s22) == fobj.exec());
    }

    SECTION("Tests const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        std::string s2 = "str2";
        std::string s22 = s2;
        const C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function2c, &obj, s1, s2));

        s1 = "failed1";
        s1 = "failed2";

        REQUIRE(obj.function2c(s11, s22) == fobj.exec());
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a ternary member function", "[tool][Bind][ternary][member][function]")
{
    SECTION("Tests non-const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        std::string s2 = "str2";
        std::string s22 = s2;
        std::string s3 = "str3";
        std::string s33 = s3;
        C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function3, &obj, s1, s2, s3));

        s1 = "failed1";
        s2 = "failed2";
        s3 = "failed3";

        REQUIRE(obj.function3(s11, s22, s33) == fobj.exec());
    }

    SECTION("Tests const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        std::string s2 = "str2";
        std::string s22 = s2;
        std::string s3 = "str3";
        std::string s33 = s3;
        const C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function3c, &obj, s1, s2, s3));

        s1 = "failed1";
        s1 = "failed2";
        s3 = "failed3";

        REQUIRE(obj.function3c(s11, s22, s33) == fobj.exec());
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a quaternary member function", "[tool][Bind][quaternary][member][function]")
{
    SECTION("Tests non-const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        std::string s2 = "str2";
        std::string s22 = s2;
        std::string s3 = "str3";
        std::string s33 = s3;
        std::string s4 = "str4";
        std::string s44 = s4;
        C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function4, &obj, s1, s2, s3, s4));

        s1 = "failed1";
        s2 = "failed2";
        s3 = "failed3";
        s4 = "failed4";

        REQUIRE(obj.function4(s11, s22, s33, s44) == fobj.exec());
    }

    SECTION("Tests const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        std::string s2 = "str2";
        std::string s22 = s2;
        std::string s3 = "str3";
        std::string s33 = s3;
        std::string s4 = "str4";
        std::string s44 = s4;
        const C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function4c, &obj, s1, s2, s3, s4));

        s1 = "failed1";
        s1 = "failed2";
        s3 = "failed3";
        s4 = "failed4";

        REQUIRE(obj.function4c(s11, s22, s33, s44) == fobj.exec());
    }
}
////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests binding a call to a quinary member function", "[tool][Bind][quinary][member][function]")
{
    SECTION("Tests non-const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        std::string s2 = "str2";
        std::string s22 = s2;
        std::string s3 = "str3";
        std::string s33 = s3;
        std::string s4 = "str4";
        std::string s44 = s4;
        std::string s5 = "str5";
        std::string s55 = s5;
        C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function5, &obj, s1, s2, s3, s4, s5));

        s1 = "failed1";
        s2 = "failed2";
        s3 = "failed3";
        s4 = "failed4";
        s5 = "failed5";

        REQUIRE(obj.function5(s11, s22, s33, s44, s55) == fobj.exec());
    }

    SECTION("Tests const version")
    {
        std::string s1 = "str1";
        std::string s11 = s1;
        std::string s2 = "str2";
        std::string s22 = s2;
        std::string s3 = "str3";
        std::string s33 = s3;
        std::string s4 = "str4";
        std::string s44 = s4;
        std::string s5 = "str5";
        std::string s55 = s5;
        const C obj;

        FObjectBase const & fobj = keep(tool::bind(&C::function5c, &obj, s1, s2, s3, s4, s5));

        s1 = "failed1";
        s1 = "failed2";
        s3 = "failed3";
        s4 = "failed4";
        s5 = "failed5";

        REQUIRE(obj.function5c(s11, s22, s33, s44, s55) == fobj.exec());
    }
}
////////////////////////////////////////////////////////////////////////////////

namespace
{
////////////////////////////////////////////////////////////////////////////////
std::string function0()
{
    return std::string("test");
}
////////////////////////////////////////////////////////////////////////////////
std::string function1(std::string const & s1)
{
    return std::string("test") + s1;
}
////////////////////////////////////////////////////////////////////////////////
std::string function2(std::string const & s1, std::string const & s2)
{
    return std::string("test") + s1 + s2;
}
////////////////////////////////////////////////////////////////////////////////
std::string function3(std::string const & s1, std::string const & s2, std::string const & s3)
{
    return std::string("test") + s1 + s2 + s3;
}
////////////////////////////////////////////////////////////////////////////////
std::string function4(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4)
{
    return std::string("test") + s1 + s2 + s3 + s4;
}
////////////////////////////////////////////////////////////////////////////////
std::string function5(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4, std::string const & s5)
{
    return std::string("test") + s1 + s2 + s3 + s4 + s5;
}
////////////////////////////////////////////////////////////////////////////////
}

namespace
{
////////////////////////////////////////////////////////////////////////////////
std::string C::function0()
{
    return std::string("C::test");
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function0c() const
{
    return std::string("C::testc");
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function1(std::string const & s1)
{
    return std::string("C::test") + s1;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function1c(std::string const & s1) const
{
    return std::string("C::testc") + s1;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function2(std::string const & s1, std::string const & s2)
{
    return std::string("C::test") + s1 + s2;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function2c(std::string const & s1, std::string const & s2) const
{
    return std::string("C::testc") + s1 + s2;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function3(std::string const & s1, std::string const & s2, std::string const & s3)
{
    return std::string("C::test") + s1 + s2 + s3;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function3c(std::string const & s1, std::string const & s2, std::string const & s3) const
{
    return std::string("C::testc") + s1 + s2 + s3;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function4(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4)
{
    return std::string("C::test") + s1 + s2 + s3 + s4;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function4c(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4) const
{
    return std::string("C::testc") + s1 + s2 + s3 + s4;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function5(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4, std::string const & s5)
{
    return std::string("C::test") + s1 + s2 + s3 + s4 + s5;
}
////////////////////////////////////////////////////////////////////////////////
std::string C::function5c(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4, std::string const & s5) const
{
    return std::string("C::testc") + s1 + s2 + s3 + s4 + s5;
}
////////////////////////////////////////////////////////////////////////////////
}
