/**
 * @file max_subarray.hpp
 * @brief Поиск максимального подмассива
 * @author Ленву С.А.
 *
 * @note Задача заключается в поиске непустого непрерывного подмассива,
 * значения которого имеют наибольшую сумму.
 * Например для массива A = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5,
 * -22, 15, 4, 7} решение будет подмассив a = {18, 20, -7, 12}.
 *
 * @note Описание общей идеи решения
 * @note Cложность по времени: O(n*lg(n))
 * @note Сложность по памяти: O(1)
 */

#pragma once

#include <vector>

/**
 * @namespace array
 * @brief Обработка массивов
 */
namespace array {

/**
 * @namespace maxsubarray
 * @brief Сортирвка вставками
 */
namespace maxsub {

std::vector<int> solve(std::vector<int>& seq);

}  // namespace maxsub

}  // namespace array
