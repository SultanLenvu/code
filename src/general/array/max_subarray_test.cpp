#include <gtest/gtest.h>

#include "general/array/max_subarray.hpp"

TEST(MaxSubarray, TestCase1) {
  std::vector<int> array{13, -3, -25, 20, -3,  -16, -23, 18,
                         20, -7, 12,  -5, -22, 15,  4,   7};
  std::vector<int> answere{18, 20, -7, 12};

  std::span<int> input(array), output;

  array::maxsub::solve2(input, output);
  std::vector<int> result(output.begin(), output.end());

  EXPECT_EQ(result, answere);
}

TEST(MaxSubarray, TestCase2) {
  std::vector<int> array{1, 1, 1, 1, 1};
  std::vector<int> answere{1, 1, 1, 1, 1};

  std::span<int> input(array), output;

  array::maxsub::solve2(input, output);
  std::vector<int> result(output.begin(), output.end());

  EXPECT_EQ(result, answere);
}

TEST(MaxSubarray, TestCase3) {
  std::vector<int> array{-1, -1, -1, -1, -1};
  std::vector<int> answere{-1};

  std::span<int> input(array), output;

  array::maxsub::solve2(input, output);
  std::vector<int> result(output.begin(), output.end());

  EXPECT_EQ(result, answere);
}

TEST(MaxSubarray, TestCase4) {
  std::vector<int> array{-2, -1, -1, -1, -1};
  std::vector<int> answere{-1};

  std::span<int> input(array), output;

  array::maxsub::solve2(input, output);
  std::vector<int> result(output.begin(), output.end());

  EXPECT_EQ(result, answere);
}

TEST(MaxSubarray, TestCase5) {
  std::vector<int> array{-100, -20, 20, 30, -10, 40, -10, 100, -500};
  std::vector<int> answere{20, 30, -10, 40, -10, 100};

  std::span<int> input(array), output;

  array::maxsub::solve2(input, output);
  std::vector<int> result(output.begin(), output.end());

  EXPECT_EQ(result, answere);
}

TEST(MaxSubarray, TestCase6) {
  std::vector<int> array{-100, -50, 200, -210, 100, 40, 50, -100};
  std::vector<int> answere{200};

  std::span<int> input(array), output;

  array::maxsub::solve2(input, output);
  std::vector<int> result(output.begin(), output.end());

  EXPECT_EQ(result, answere);
}