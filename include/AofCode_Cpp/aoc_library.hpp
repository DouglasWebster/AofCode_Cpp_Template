#ifndef AOC_LIBRARY_HPP
#define AOC_LIBRARY_HPP

#include <AofCode_Cpp/aoc_library_export.hpp>

[[nodiscard]] AOC_LIBRARY_EXPORT int factorial(int) noexcept;

[[nodiscard]] constexpr int factorial_constexpr(int input) noexcept
{
  if (input == 0) { return 1; }

  return input * factorial_constexpr(input - 1);
}

#endif
