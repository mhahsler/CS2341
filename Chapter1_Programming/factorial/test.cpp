// NOTE: We use Catch2 V2
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "factorial.h"



TEST_CASE("Factorials are computed", "[factorial]")
{
    
    REQUIRE(Factorial(0) == 1);
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

// TEST_CASE("Example of a test that fails.", "[factorial]")
// {
//     REQUIRE(Factorial(0) == 0); // this is a wrong 0! should be 1)
// }
