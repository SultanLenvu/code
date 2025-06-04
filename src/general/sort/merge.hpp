/**
 * @file merge.hpp
 * @brief Сортировка слиянием
 * @author Ленву С.А.
 *
 *
 * @note Описание общей идеи решения
 * @note Cложность по времени: O(n*lg(n))
 * @note Сложность по памяти: O(1)
 */

#pragma once

#include <vector>

/**
 * @namespace sort
 * @brief Реализации алгоритмов сортировки
 */
namespace sort {

/**
 * @namespace merge
 * @brief Сортирвка слиянием
 */
namespace merge {

void solve(std::vector<int>& seq);

}  // namespace merge

}  // namespace sort
