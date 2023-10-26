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
    CHECK_THROWS(factorial(-1));
    // Note: this does not work since we can't test negative numbers because the argument is unsigned! This 
    // is a design issue!
    
    CHECK(factorial(100) == 9.332622e+157);
    // This test fails because we return an unsigned int. Another design issue!
}

