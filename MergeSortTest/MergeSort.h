/**
 * @file MergeSort.h
 * @brief Definicja klasy MergeSort implementuj¹cej algorytm sortowania przez scalanie (Merge Sort).
 *
 * ### Merge Sort - G³ówne za³o¿enia
 * - **Z³o¿onoœæ czasowa**:
 *   - Œrednia: O(n log n)
 *   - Najgorszy przypadek: O(n log n)
 *   - Najlepszy przypadek: O(n log n)
 * - **Z³o¿onoœæ pamiêciowa**:
 *   - O(n), poniewa¿ wymaga dodatkowej pamiêci na przechowywanie podwektorów.
 * - **Stabilnoœæ**:
 *   - Algorytm zachowuje stabilnoœæ (nie zmienia kolejnoœci elementów o tych samych wartoœciach).
 *
 * Diagram przep³ywu (schemat dzia³ania):
 *
 * \dot
 * digraph MergeSort {
 *   node [shape=box];
 *   Start -> Divide -> "Sort Left" -> "Sort Right" -> Merge -> End;
 * }
 * \enddot
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector> ///< Dynamiczne tablice umo¿liwiaj¹ce elastyczne zarz¹dzanie danymi.

 /**
  * @class MergeSort
  * @brief Klasa implementuj¹ca algorytm sortowania przez scalanie.
  *
  * ### Przeznaczenie:
  * Klasa s³u¿y do sortowania wektorów liczb ca³kowitych w kolejnoœci rosn¹cej.
  * Umo¿liwia ³atwe i szybkie sortowanie du¿ych zbiorów danych.
  *
  * #### G³ówne metody:
  * - `sort`: Punkt wejœciowy algorytmu.
  * - `mergeSort`: Funkcja rekurencyjna dziel¹ca zbiór na mniejsze czêœci.
  * - `merge`: Funkcja ³¹cz¹ca dwa posortowane podzbiory.
  */
class MergeSort {
public:
    /**
     * @brief Sortuje podany wektor liczb ca³kowitych w kolejnoœci rosn¹cej.
     *
     * Funkcja jest punktem wejœciowym algorytmu Merge Sort.
     * Wywo³uje rekurencyjn¹ funkcjê `mergeSort`.
     *
     * #### Przyk³ad:
     * \code{.cpp}
     * MergeSort sorter;
     * std::vector<int> array = {5, 3, 8, 6, 2};
     * sorter.sort(array);
     * \endcode
     *
     * @param array Wektor liczb ca³kowitych do posortowania.
     */
    void sort(std::vector<int>& array);

private:
    /**
     * @brief Dzieli tablicê na mniejsze czêœci i sortuje je rekurencyjnie.
     *
     * Funkcja dzieli tablicê na dwie po³owy, sortuje ka¿d¹ z nich rekurencyjnie,
     * a nastêpnie ³¹czy je w jedn¹ ca³oœæ.
     *
     * @param array Wektor liczb ca³kowitych do posortowania.
     * @param left Indeks pocz¹tkowy zakresu do posortowania.
     * @param right Indeks koñcowy zakresu do posortowania.
     */
    void mergeSort(std::vector<int>& array, int left, int right);

    /**
     * @brief £¹czy dwa posortowane podwektory w jeden.
     *
     * Tworzy dwa tymczasowe wektory przechowuj¹ce elementy z lewej i prawej czêœci,
     * a nastêpnie kopiuje je w odpowiedniej kolejnoœci do oryginalnego wektora.
     *
     * #### Diagram przep³ywu:
     * \msc
     * User, MergeSort;
     * User->MergeSort [label="sort(array)"];
     * MergeSort=>MergeSort [label="mergeSort(array, left, middle)"];
     * MergeSort=>MergeSort [label="mergeSort(array, middle + 1, right)"];
     * MergeSort->MergeSort [label="merge(array, left, middle, right)"];
     * \endmsc
     *
     * @param array Wektor liczb ca³kowitych do posortowania.
     * @param left Indeks pocz¹tkowy pierwszego podwektora.
     * @param middle Œrodkowy indeks (koniec pierwszego podwektora).
     * @param right Indeks koñcowy drugiego podwektora.
     */
    void merge(std::vector<int>& array, int left, int middle, int right);
};

#endif // MERGESORT_H