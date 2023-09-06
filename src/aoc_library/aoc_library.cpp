#include <AofCode_Cpp/aoc_library.hpp>

int AoCLib::factorial(int input) noexcept
{
  int result = 1;

  while (input > 0) {
    result *= input;
    --input;
  }

  return result;
}
