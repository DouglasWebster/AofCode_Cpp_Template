#include <catch2/catch_test_macros.hpp>


#include <AofCode_Cpp/aoc_library.hpp>


TEST_CASE("Factorials are computed", "[factorial]")
{
  REQUIRE(AoCLib::factorial(0) == 1);
  REQUIRE(AoCLib::factorial(1) == 1);
  REQUIRE(AoCLib::factorial(2) == 2);
  REQUIRE(AoCLib::factorial(3) == 6);
  REQUIRE(AoCLib::factorial(10) == 3628800);
}
