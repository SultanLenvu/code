#include "task1.hpp"

#include <unordered_map>

namespace leetcode {
namespace task1 {

std::vector<int> solve(const std::vector<int>& nums, int target) {
  std::unordered_map<int, int> numMap;
  int n = nums.size();

  for (auto i = 0; i < n; ++i) {
    int complement = target - nums[i];
    if (numMap.count(complement)) {
      return {i, numMap[complement]};
    }
    numMap[nums[i]] = i;
  }

  return {};
}

}  // namespace task1
}  // namespace leetcode
