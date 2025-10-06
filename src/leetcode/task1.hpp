/**
 * @file task1.hpp
 * @brief Поиск двух элементов массива с заданной суммой
 * @author Ленву С.А.
 *
 * @note https://leetcode.com/problems/two-sum/description/
 *
 *
 * @note Сложность по времени: O(n).
 * @note Сложность по памяти: O(n).
 */

#pragma once

#include <vector>

namespace leetcode::task1 {

std::vector<int> solve(const std::vector<int>& nums, int target);

}  // namespace leetcode::task1
