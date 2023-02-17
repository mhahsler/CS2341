#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "factorial.h"

// You can add more test cases here and add more test executables in
// CMakeLists.txt
TEST_CASE("Simple Factorials", "[factorial]")
{
    
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
    
    // issue cases
    // we can't test negative numbers because the argument is unsigned.
    // CHECK_THROWS(factorial(-1));
    CHECK(factorial(100) == 9.332622e+157);
}

