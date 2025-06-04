#include <gtest/gtest.h>

#include "general/array/max_subarray.hpp"

TEST(MaxSubarray, TestCase1) {
  std::vector<int> array{13, -3, -25, 20, -3,  -16, -23, 18,
                         20, -7, 12,  -5, -22, 15,  4,   7};
  std::vector<int> answere{18, 20, -7, 12};

  std::span<int> input(array), output;

  array::maxsub::solve1(input, output);
  std::vector<int> result(output.begin(), output.end());

  EXPECT_EQ(result, answere);
}
