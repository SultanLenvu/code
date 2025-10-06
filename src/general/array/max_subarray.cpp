#include "max_subarray.hpp"

namespace array::maxsub {

static int findMaxCrossSubarray(const std::span<int>& array,
                                std::span<int>& maxSubarray);

int solve1(const std::span<int>& array, std::span<int>& maxSubarray) {
  if (array.size() == 1) {
    maxSubarray = array;
    return array[0];
  }

  auto mid = array.size() / 2;

  auto leftPart = array.subspan(0, mid);
  std::span<int> leftMaxSub;
  auto leftMax = solve1(leftPart, leftMaxSub);

  auto rigthPart = array.subspan(mid);
  std::span<int> rightMaxSub;
  auto rigthMax = solve1(rigthPart, rightMaxSub);

  std::span<int> crossMaxSub;
  auto crossMax = findMaxCrossSubarray(array, crossMaxSub);

  if (leftMax >= rigthMax && leftMax >= crossMax) {
    maxSubarray = leftMaxSub;
    return leftMax;
  } else if (rigthMax >= leftMax && rigthMax >= crossMax) {
    maxSubarray = rightMaxSub;
    return rigthMax;
  } else {
    maxSubarray = crossMaxSub;
    return crossMax;
  }
}

int solve2(const std::span<int>& array, std::span<int>& maxSubarray) {
  if (array.size() == 1) {
    maxSubarray = array;
    return array[0];
  }

  int maxSum = array[0], rightSum = array[0];
  int maxBegin = 0, maxEnd = 0, rightBegin = 0;

  for (int i = 1; i < array.size(); ++i) {
    rightSum += array[i];

    if (array[i] > rightSum) {
      rightSum = array[i];
      rightBegin = i;
    }

    if (rightSum > maxSum) {
      maxSum = rightSum;
      maxBegin = rightBegin;
      maxEnd = i;
    }
  }

  maxSubarray = array.subspan(maxBegin, maxEnd - maxBegin + 1);
  return maxSum;
}

int findMaxCrossSubarray(const std::span<int>& array,
                         std::span<int>& maxSubarray) {
  int sum = 0;
  size_t mid = array.size() / 2;
  int leftSum = array[mid - 1], rigthSum = array[mid];
  size_t maxLeft = mid - 1, maxRight = mid;

  sum = leftSum;
  for (int i = mid - 2; i >= 0; --i) {
    sum += array[i];
    if (sum > leftSum) {
      leftSum = sum;
      maxLeft = i;
    }
  }

  sum = rigthSum;
  for (int i = mid + 1; i < array.size(); ++i) {
    sum += array[i];
    if (sum > rigthSum) {
      rigthSum = sum;
      maxRight = i;
    }
  }

  maxSubarray = array.subspan(maxLeft, maxRight - maxLeft + 1);
  return leftSum + rigthSum;
}

}  // namespace array::maxsub
