#include "morton.hpp"
#include <cstdint>
#include <utility>
#include <cassert>
#include <iostream>
#include <random>

int main()
{
  std::minstd_rand rng;
  for(int i = 0; i < 1000; ++i)
  {
    std::pair<std::uint32_t,std::uint32_t> xy(rng(), rng());

    std::uint64_t morton_code = encode_morton_2d(xy);

    std::pair<std::uint32_t,std::uint32_t> decoded = decode_morton_2d(morton_code);

    assert(decoded == xy);
  }

  std::cout << "OK" << std::endl;

  return 0;
}

