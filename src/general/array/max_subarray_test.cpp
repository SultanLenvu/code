#include <gtest/gtest.h>

#include "general/array/max_subarray.hpp"

TEST(MaxSubarray, TestCase1) {
  std::vector<int> array{13, -3, -25, 20, -3,  -16, -23, 18,
                         20, -7, 12,  -5, -22, 15,  4,   7};
  std::vector<int> subarray{18, 20, -7, 12};

  EXPECT_EQ(array, subarray);
}
