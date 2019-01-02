/**
 * @brief Catch tests for rational class
 * @file rationalcatch.cpp
 *
 * @author Yusuf Pisan
 * @date 7 Dec 2018
 */

#include <sstream>
#include "catch.hpp"
#include "rational.h"

using namespace std;

// Testing vectors using CATCH using SECTIONs
TEST_CASE("R constructor, reduce") {
  Rational rempty;
  Rational r3(3);
  Rational r35(3, 5);
  Rational r3050(30, 50);
  REQUIRE(rempty.getNumerator() == 0);
  REQUIRE(rempty.getDenominator() == 1);
  REQUIRE(r3.getNumerator() == 3);
  REQUIRE(r3.getDenominator() == 1);
  REQUIRE(r35.getNumerator() == 3);
  REQUIRE(r35.getDenominator() == 5);
  REQUIRE(r3050.getNumerator() == 3);
  REQUIRE(r3050.getDenominator() == 5);
}

TEST_CASE("R insertion, extraction") {
  ostringstream out;
  istringstream is;
  Rational r3(3);
  Rational r35(3, 5);
  operator<<(out, r3);
  REQUIRE(out.str() == "3");

  out.str("");
  operator<<(out, r35);
  REQUIRE(out.str() == "3/5");

  is.str("12 30");
  Rational r23;
  operator>>(is, r23);
  REQUIRE(r23.getNumerator() == 2);
  REQUIRE(r23.getDenominator() == 5);
}

TEST_CASE("R basic math") {
  Rational r12(1, 2);
  Rational r23(2, 3);

  SECTION("add") {
    Rational r = r12 + r23;
    REQUIRE(r.getNumerator() == 7);
    REQUIRE(r.getDenominator() == 6);

    r12 += r23;
    REQUIRE(r == r12);
  }

  SECTION("subtract") {
    Rational r = r12 - r23;
    REQUIRE(r.getNumerator() == -1);
    REQUIRE(r.getDenominator() == 6);

    r12 -= r23;
    REQUIRE(r == r12);
  }

  SECTION("multiply") {
    Rational r = r12 * r23;
    REQUIRE(r.getNumerator() == 1);
    REQUIRE(r.getDenominator() == 3);

    r12 *= r23;
    REQUIRE(r == r12);
  }

  SECTION("divide") {
    Rational r = r12 / r23;
    REQUIRE(r.getNumerator() == 3);
    REQUIRE(r.getDenominator() == 4);

    r12 /= r23;
    REQUIRE(r == r12);
  }
}

TEST_CASE("R compare") {
  Rational r12(1, 2);
  Rational r23(2, 3);
  Rational r2030(20, 30);
  REQUIRE(r12 < r23);
  REQUIRE(r12 <= r23);
  REQUIRE(r12 != r23);
  REQUIRE(r23 > r12);
  REQUIRE(r23 >= r12);
  REQUIRE(r23 == r2030);
}

TEST_CASE("R extras") {
  ostringstream out;
  Rational r125(12, 5);
  Rational r23(2, 3);
  Rational r46(4, 6);

  int itwo = static_cast<int>(r125);
  REQUIRE(itwo == 2);

  int izero = static_cast<int>(r23);
  REQUIRE(izero == 0);

  Rational r = r23 - r46;
  operator<<(out, r);
  REQUIRE(out.str() == "0");

  Rational rerr = r125 / r;
  out.str("");
  operator<<(out, rerr);
  REQUIRE(out.str() == "\nDIVIDE BY ZERO ERROR!!!\n");
}


