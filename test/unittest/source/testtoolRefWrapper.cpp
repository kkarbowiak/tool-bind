#include "catch/catch.hpp"

#include "toolRefWrapper.h"

#include <string>


////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Tests construction and implicit conversion of wrapper", "[tool][RefWrapper]")
{
    SECTION("Tests non-const version")
    {
        SECTION("Tests specific specialisation (int)")
        {
            int i = 5;

            tool::wrapper<int> wi(i);

            int & ir = wi;

            REQUIRE(i == ir);

            i = 7;

            REQUIRE(i == ir);
        }

        SECTION("Tests specific specialisation (std::string)")
        {
            std::string s = "wrapper";

            tool::wrapper<std::string> ws(s);

            std::string & sr = ws;

            REQUIRE(s == sr);

            s = "text";

            REQUIRE(s == sr);
        }
    }

    SECTION("Tests const version")
    {
        SECTION("Tests specific specialisation (int)")
        {
            const int ci = 5;

            tool::wrapper<const int> cwi(ci);

            int const & icr = cwi;

            REQUIRE(ci == icr);
        }

        SECTION("Tests specific specialisation (std::string)")
        {
            const std::string cs = "wrapper";

            tool::wrapper<const std::string> cws(cs);

            std::string const & scr = cws;

            REQUIRE(cs == scr);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace
{
////////////////////////////////////////////////////////////////////////////////
inline std::ostream & operator<<(std::ostream & s, tool::wrapper<int> const & w)
{
    int const & tref = w;

    s << tref;

    return s;
}
////////////////////////////////////////////////////////////////////////////////
}
