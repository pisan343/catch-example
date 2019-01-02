/**
 * @brief CATCH example vector
 * @file vectorcatch.cpp
 *
 * @author Yusuf Pisan
 * @date 7 Dec 2018
 */

#include "catch.hpp"

// Testing vectors using CATCH using SECTIONs
TEST_CASE("v1: vectors can be sized and resized", "[vector]") {
  std::vector<int> v(5);

  REQUIRE(v.size() == 5);
  REQUIRE(v.capacity() >= 5);

  SECTION("resizing bigger changes size and capacity") {
    v.resize(10);

    REQUIRE(v.size() == 10);
    REQUIRE(v.capacity() >= 10);
  }

  SECTION("resizing smaller changes size but not capacity") {
    v.resize(0);

    REQUIRE(v.empty());
    REQUIRE(v.capacity() >= 5);
  }

  SECTION("reserving bigger changes capacity but not size") {
    v.reserve(10);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 10);
  }

  SECTION("reserving smaller does not change size or capacity") {
    v.reserve(0);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);
    // next test is intended to fail
    REQUIRE(v.size() == -1);
  }
}

// Testing vectors using GIVEN REQUIRE WHEN THEN framework
SCENARIO("v2: vectors can be sized and resized", "[vector]") {
  GIVEN("A vector with some items") {
    std::vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);

    WHEN("the size is increased") {
      v.resize(10);

      THEN("the size and capacity change") {
        REQUIRE(v.size() == 10);
        REQUIRE(v.capacity() >= 10);
      }
    }WHEN("the size is reduced") {
      v.resize(0);

      THEN("the size changes but not capacity") {
        REQUIRE(v.empty());
        REQUIRE(v.capacity() >= 5);
      }
    }WHEN("more capacity is reserved") {
      v.reserve(10);

      THEN("the capacity changes but not the size") {
        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 10);
      }
    }WHEN("less capacity is reserved") {
      v.reserve(0);

      THEN("neither size nor capacity are changed") {
        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 5);
        // next test is intended to fail
        REQUIRE(v.size() == -1);
      }
    }
  }
}
