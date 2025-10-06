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

namespace array::maxsub {

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
 *
 * @note Логика решения:
 * MAX_LAST(A[1]) = A[1]
 * MAX(A[1]) = A[1]
 *
 * MAX(A[1..2]) = MAX(A[1]) || MAX_LAST(A[1..2])
 * MAX_LAST(A[1..2]) = MAX_LAST(A[1]) + A[2] || A[2]
 *
 * MAX(A[1..3]) = MAX(A[1..2]) || MAX_LAST(A[1..3])
 * MAX_LAST(A[1..3]) = MAX_LAST(A[1..2]) + A[3] || A[3]
 * ...
 * MAX(A[1..j]) = MAX(A[1..j-1]) || MAX_LAST(A[1..j])
 * MAX_LAST(A[1..j]) = MAX_LAST(A[1..j - 1]) + A[j] || A[j]
 *
 * MAX(A[1..j + 1]) = MAX(A[1..j]) || MAX_LAST(A[1..j + 1])
 * MAX_LAST(A[1..j + 1) = MAX_LAST(A[1..j]) + A[j + 1] || A[j + 1]
 *
 */
int solve2(const std::span<int>& array, std::span<int>& maxSubarray);

}  // namespace array::maxsub
