#define RUN_TESTS ///< Flaga preprocesora w³¹czaj¹ca tryb testowy.
#include "pch.h" ///< Wstêpnie kompilowane nag³ówki dla projektu.
#include "gtest/gtest.h" ///< Nag³ówek Google Test do implementacji testów jednostkowych.
#include "MergeSort.h" ///< Plik nag³ówkowy klasy MergeSort, której metody s¹ testowane.
#include <vector> ///< Biblioteka standardowa dla dynamicznych tablic.

/**
 * @brief Testuje algorytm na tablicy, która ju¿ jest posortowana.
 *
 * ### Cel testu:
 * Sprawdzamy, czy algorytm Merge Sort nie wprowadza niepotrzebnych zmian w tablicy, która jest ju¿ poprawnie posortowana.
 *
 * ### Przyk³adowy scenariusz:
 * - Wejœcie: {1, 2, 3, 4, 5}
 * - Oczekiwane wyjœcie: {1, 2, 3, 4, 5}
 *
 * #### Diagram przep³ywu:
 * \msc
 * User, MergeSort;
 * User->MergeSort [label="sort(array)"];
 * MergeSort=>MergeSort [label="mergeSort(array, left, right)"];
 * MergeSort=>MergeSort [label="merge(array, left, middle, right)"];
 * User<-MergeSort [label="array sorted"];
 * \endmsc
 */
TEST(MergeSortTest, AlreadySortedArray) {
    MergeSort sorter; ///< Inicjalizacja obiektu klasy MergeSort.
    std::vector<int> array = { 1, 2, 3, 4, 5 }; ///< Tablica wejœciowa, która ju¿ jest posortowana.
    sorter.sort(array); ///< Wywo³anie algorytmu Merge Sort.
    EXPECT_EQ(array, (std::vector<int>{1, 2, 3, 4, 5})); ///< Sprawdzenie, czy tablica pozosta³a niezmieniona.
}

/**
 * @brief Testuje algorytm na tablicy posortowanej w odwrotnej kolejnoœci.
 *
 * ### Cel testu:
 * Weryfikacja, czy algorytm Merge Sort potrafi odwróciæ kolejnoœæ elementów w tablicy i posortowaæ j¹ rosn¹co.
 *
 * ### Przyk³adowy scenariusz:
 * - Wejœcie: {5, 4, 3, 2, 1}
 * - Oczekiwane wyjœcie: {1, 2, 3, 4, 5}
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
 * ### Cel testu:
 * Weryfikacja poprawnego sortowania losowego zbioru liczb.
 *
 * ### Przyk³adowy scenariusz:
 * - Wejœcie: {4, 2, 7, 3, 1}
 * - Oczekiwane wyjœcie: {1, 2, 3, 4, 7}
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
 * ### Cel testu:
 * Sprawdzenie, czy algorytm prawid³owo obs³uguje liczby ujemne i sortuje je w kolejnoœci rosn¹cej.
 *
 * ### Przyk³adowy scenariusz:
 * - Wejœcie: {-5, -2, -3, -1}
 * - Oczekiwane wyjœcie: {-5, -3, -2, -1}
 */
TEST(MergeSortTest, NegativeNumbers) {
    MergeSort sorter;
    std::vector<int> array = { -5, -2, -3, -1 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{-5, -3, -2, -1}));
}

/**
 * @brief Testuje algorytm na tablicy mieszanej (liczby dodatnie i ujemne).
 *
 * ### Cel testu:
 * Weryfikacja poprawnego sortowania liczb dodatnich i ujemnych w jednym zbiorze.
 *
 * ### Przyk³adowy scenariusz:
 * - Wejœcie: {-3, 2, -1, 4}
 * - Oczekiwane wyjœcie: {-3, -1, 2, 4}
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
 * ### Cel testu:
 * Sprawdzenie, czy algorytm poprawnie obs³uguje pust¹ tablicê bez b³êdów.
 *
 * ### Przyk³adowy scenariusz:
 * - Wejœcie: {}
 * - Oczekiwane wyjœcie: {}
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
 * ### Cel testu:
 * Weryfikacja, czy algorytm pozostawia tablicê z jednym elementem bez zmian.
 *
 * ### Przyk³adowy scenariusz:
 * - Wejœcie: {1}
 * - Oczekiwane wyjœcie: {1}
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
 * ### Cel testu:
 * Sprawdzenie, czy algorytm poprawnie sortuje tablicê z powtarzaj¹cymi siê wartoœciami.
 *
 * ### Przyk³adowy scenariusz:
 * - Wejœcie: {4, 2, 4, 2}
 * - Oczekiwane wyjœcie: {2, 2, 4, 4}
 */
TEST(MergeSortTest, ArrayWithDuplicates) {
    MergeSort sorter;
    std::vector<int> array = { 4, 2, 4, 2 }; ///< Tablica z duplikatami.
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{2, 2, 4, 4}));
}