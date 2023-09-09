#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>


#include <AofCode_Cpp/aoc_library.hpp>


TEST_CASE("Vectorise integer data", "[vectorise]")
{
  using Catch::Matchers::IsEmpty;
  auto empty_vector = std::vector<std::vector<int>>{};

  REQUIRE_THAT(AoCLib::vectorise_int_data(""), IsEmpty());
}