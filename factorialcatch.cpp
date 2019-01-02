/**
 * @brief CATCH example factorial
 * @file factorialcatch.cpp
 *
 * @author Yusuf Pisan
 * @date 7 Dec 2018
 */

#include "catch.hpp"

//  Calculate factorial
unsigned int Factorial(unsigned int number) {
  return number <= 1 ? number : Factorial(number - 1) * number;
}

// Simple CATCH tests for factorial
TEST_CASE("f1: Factorials are computed", "[factorial]") {
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
  REQUIRE(Factorial(10) == 3628800);
  // next test is intended to fail
  REQUIRE(Factorial(2) == -1);
}

// Another set of factorial tests
TEST_CASE("f2: Factorials are computed", "[factorial2]") {
  REQUIRE(Factorial(1) == 1);
  // next test is intended to fail
  REQUIRE(Factorial(3) == -1);
}
