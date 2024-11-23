#include "MergeSort.h"
#include "pch.h"
/**
 * @brief G³ówna funkcja sortuj¹ca dla algorytmu Merge Sort.
 *
 * Funkcja rozpoczyna proces sortowania, sprawdzaj¹c, czy tablica jest pusta.
 * Jeœli tablica nie jest pusta, wywo³uje funkcjê `mergeSort`, aby posortowaæ tablicê.
 *
 * @param array Wektor liczb ca³kowitych do posortowania.
 */
void MergeSort::sort(std::vector<int>& array) {
    if (array.empty()) return; // Obs³uga pustej tablicy
    mergeSort(array, 0, array.size() - 1);
}
/**
 * @brief Funkcja rekursywna dziel¹ca tablicê na mniejsze czêœci.
 *
 * Funkcja dzieli tablicê na dwie po³owy: lew¹ i praw¹.
 * Nastêpnie rekurencyjnie sortuje ka¿d¹ z tych czêœci.
 * Po posortowaniu obu czêœci, scala je w jedn¹ ca³oœæ za pomoc¹ funkcji `merge`.
 *
 * @param array Wektor liczb ca³kowitych do posortowania.
 * @param left Indeks pocz¹tkowy podwektora.
 * @param right Indeks koñcowy podwektora.
 */

void MergeSort::mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}
/**
 * @brief Funkcja scalaj¹ca dwa posortowane podwektory.
 *
 * Funkcja tworzy dwa tymczasowe wektory: lewy i prawy, które przechowuj¹ odpowiednie czêœci tablicy.
 * Nastêpnie porównuje elementy z obu wektorów i kopiuje je w odpowiedniej kolejnoœci do oryginalnej tablicy.
 * Jeœli któryœ z wektorów zostanie przetworzony wczeœniej, pozosta³e elementy z drugiego wektora s¹ dodawane na koniec.
 *
 * @param array Wektor liczb ca³kowitych do posortowania.
 * @param left Indeks pocz¹tkowy pierwszego podwektora.
 * @param middle Indeks koñcowy pierwszego podwektora i pocz¹tek drugiego.
 * @param right Indeks koñcowy drugiego podwektora.
 */
void MergeSort::merge(std::vector<int>& array, int left, int middle, int right) {
    std::vector<int> leftArray(array.begin() + left, array.begin() + middle + 1);
    std::vector<int> rightArray(array.begin() + middle + 1, array.begin() + right + 1);

    int i = 0, j = 0, k = left;
    // Scalanie elementów z obu podwektorów do oryginalnej tablicy
    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        }
        else {
            array[k++] = rightArray[j++];
        }
    }
    // Kopiowanie pozosta³ych elementów z lewej tablicy, jeœli istniej¹
    while (i < leftArray.size()) array[k++] = leftArray[i++];
    // Kopiowanie pozosta³ych elementów z prawej tablicy, jeœli istniej¹
    while (j < rightArray.size()) array[k++] = rightArray[j++];
}