#include <AofCode_Cpp/aoc_library.hpp>

AoCLib::int_data AoCLib::vectorise_int_data(const std::string &file_name) noexcept
{
  int_data data{ { 1, 2, 3 } };
  if (file_name.empty()) { return int_data{}; }

  return data;
}
