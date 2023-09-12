#include <AofCode_Cpp/aoc_library.hpp>

#include <fstream>
#include <iostream>
#include <sstream>

AoCLib::int_data AoCLib::vectorise_int_data(const std::string &file_name) noexcept
{
  int_data data{};
  if (file_name.empty()) { return data; }

  std::ifstream source_file{ file_name };
  if (!source_file) {
    std::cerr << "Error: data file " << file_name << " could not be opened.\n";
    return data;
  }

  while (source_file) {
    std::string line_read;
    source_file >> line_read;

    std::stringstream integer_stream(line_read);

    std::vector<int> line_data{};
    int number{};
    while (integer_stream >> number) { line_data.push_back(number); };

    data.push_back(line_data);
  }

  return data;
}
