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
 */

#pragma once

#include <span>
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

/**
 * @brief Рекурсивный алгоритм
 * @note Cложность по времени: O(n*lg(n))
 * @note Сложность по памяти: O(1)
 *
 * @param array Входной массив
 * @param maxSubarray Максимальный подмассив
 * @return Сумма элементов максимального подмассива
 */
int solve1(const std::span<int>& array, std::span<int>& maxSubarray);

/**
 * @brief Нерекурсивный алгоритм
 * @note Cложность по времени: O(n)
 * @note Сложность по памяти: O(1)
 *
 * @param array Входной массив
 * @param maxSubarray Максимальный подмассив
 * @return Сумма элементов максимального подмассива
 */
int solve2(const std::span<int>& array, std::span<int>& maxSubarray);

}  // namespace maxsub

}  // namespace array
