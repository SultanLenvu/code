#include <gtest/gtest.h>

#include "general/sort/merge.hpp"

TEST(Merge, TestCase1) {
  std::vector<int> seq{12, -1, 0, 16, 2, 15, 5, 64, -50, 3, -25, 7};
  std::vector<int> result{-50, -25, -1, 0, 2, 3, 5, 7, 12, 15, 16, 64};

  sort::merge::solve(seq);
  EXPECT_EQ(seq, result);
}

TEST(Merge, TestCase2) {
  std::vector<int> seq{9, 8, 7, 6, 5, 4};
  std::vector<int> result{4, 5, 6, 7, 8, 9};

  sort::merge::solve(seq);
  EXPECT_EQ(seq, result);
}

TEST(Merge, TestCase3) {
  std::vector<int> seq{1, 1, 1, 1, 1};
  std::vector<int> result{1, 1, 1, 1, 1};

  sort::merge::solve(seq);
  EXPECT_EQ(seq, result);
}