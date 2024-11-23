#define RUN_TESTS ///< Definiuje flagê, która w³¹cza tryb testowy.
#include "pch.h" ///< Plik nag³ówkowy wstêpnie kompilowany (opcjonalny).
#include "gtest/gtest.h" ///< Nag³ówek biblioteki Google Test do testowania jednostkowego.
#include "MergeSort.h" ///< Nag³ówek klasy MergeSort, której funkcje s¹ testowane.
#include <vector> ///< Biblioteka do dynamicznych tablic (wektorów).

/**
 * @brief Testuje algorytm na tablicy, która ju¿ jest posortowana.
 *
 * Sprawdza, czy funkcja `sort` pozostawia posortowan¹ tablicê bez zmian.
 */
TEST(MergeSortTest, AlreadySortedArray) {
    MergeSort sorter; ///< Obiekt klasy MergeSort.
    std::vector<int> array = { 1, 2, 3, 4, 5 }; ///< Tablica wejœciowa.
    sorter.sort(array); ///< Wywo³anie funkcji sortuj¹cej.
    EXPECT_EQ(array, (std::vector<int>{1, 2, 3, 4, 5})); ///< Oczekiwany wynik.
}

/**
 * @brief Testuje algorytm na tablicy posortowanej w odwrotnej kolejnoœci.
 *
 * Sprawdza, czy funkcja `sort` poprawnie sortuje tablicê w kolejnoœci rosn¹cej.
 */
TEST(MergeSortTest, ReverseSortedArray) {
    MergeSort sorter;
    std::vector<int> array = { 5, 4, 3, 2, 1 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{1, 2, 3, 4, 5}));
}

/**
 * @brief Testuje algorytm na losowej tablicy liczb ca³kowitych.
 *
 * Sprawdza, czy funkcja `sort` poprawnie sortuje tablicê o losowym uk³adzie elementów.
 */
TEST(MergeSortTest, RandomArray) {
    MergeSort sorter;
    std::vector<int> array = { 4, 2, 7, 3, 1 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{1, 2, 3, 4, 7}));
}

/**
 * @brief Testuje algorytm na tablicy zawieraj¹cej wy³¹cznie liczby ujemne.
 *
 * Sprawdza, czy funkcja `sort` poprawnie sortuje tablicê z liczbami ujemnymi.
 */
TEST(MergeSortTest, NegativeNumbers) {
    MergeSort sorter;
    std::vector<int> array = { -5, -2, -3, -1 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{-5, -3, -2, -1}));
}

/**
 * @brief Testuje algorytm na tablicy zawieraj¹cej liczby dodatnie i ujemne.
 *
 * Sprawdza, czy funkcja `sort` poprawnie sortuje mieszane liczby dodatnie i ujemne.
 */
TEST(MergeSortTest, MixedNumbers) {
    MergeSort sorter;
    std::vector<int> array = { -3, 2, -1, 4 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{-3, -1, 2, 4}));
}

/**
 * @brief Testuje algorytm na pustej tablicy.
 *
 * Sprawdza, czy funkcja `sort` poprawnie obs³uguje pust¹ tablicê bez rzucania b³êdów.
 */
TEST(MergeSortTest, EmptyArray) {
    MergeSort sorter;
    std::vector<int> array; ///< Pusta tablica.
    sorter.sort(array);
    EXPECT_EQ(array, std::vector<int>{});
}

/**
 * @brief Testuje algorytm na tablicy zawieraj¹cej jeden element.
 *
 * Sprawdza, czy funkcja `sort` pozostawia tablicê bez zmian.
 */
TEST(MergeSortTest, SingleElementArray) {
    MergeSort sorter;
    std::vector<int> array = { 1 }; ///< Tablica z jednym elementem.
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{1}));
}

/**
 * @brief Testuje algorytm na tablicy zawieraj¹cej duplikaty.
 *
 * Sprawdza, czy funkcja `sort` poprawnie sortuje tablicê z powtarzaj¹cymi siê wartoœciami.
 */
TEST(MergeSortTest, ArrayWithDuplicates) {
    MergeSort sorter;
    std::vector<int> array = { 4, 2, 4, 2 }; ///< Tablica z duplikatami.
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{2, 2, 4, 4}));
}