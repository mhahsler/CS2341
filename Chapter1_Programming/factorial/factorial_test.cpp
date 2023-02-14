#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "factorial.h"

// You can add more test cases here and add more test executables in
// CMakeLists.txt
TEST_CASE("Simple Factorials", "[factorial]")
{
    
    CHECK(Factorial(0) == 1);
    CHECK(Factorial(1) == 1);
    CHECK(Factorial(2) == 2);
    CHECK(Factorial(3) == 6);
    CHECK(Factorial(10) == 3628800);
    
    // issue cases
    CHECK_THROWS(Factorial(-1));
    CHECK(Factorial(100) == 9.332622e+157);
}

