#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>


#include <AofCode_Cpp/aoc_library.hpp>


#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <memory>
#include <sstream>


TEST_CASE("Vectorise integer data", "[vectorise]")
{
  using Catch::Matchers::IsEmpty;
  auto empty_vector = std::vector<std::vector<int>>{};

  std::stringstream tmp_file;
  tmp_file << tmpnam(nullptr);// NOLINT: This is not thread safe!

  SECTION("an empty or invalid file name returns and empty vector ")
  {
    REQUIRE_THAT(AoCLib::vectorise_int_data(""), IsEmpty());
    REQUIRE_THAT(AoCLib::vectorise_int_data(tmp_file.str()), IsEmpty());
  }
}