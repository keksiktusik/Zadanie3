#include "MergeSort.h"
#include "pch.h"

/**
 * @brief Implementacja metody `sort`.
 *
 * Metoda sprawdza, czy tablica jest pusta. Jeœli nie, wywo³uje rekurencyjn¹ metodê `mergeSort`.
 *
 * @param array Wektor liczb ca³kowitych do posortowania.
 */
void MergeSort::sort(std::vector<int>& array) {
    if (array.empty()) return; ///< Obs³uga przypadku pustej tablicy.
    mergeSort(array, 0, array.size() - 1); ///< Rozpoczêcie procesu sortowania.
}

/**
 * @brief Implementacja metody `mergeSort`.
 *
 * Funkcja dzieli tablicê na mniejsze czêœci i sortuje ka¿d¹ z nich rekurencyjnie.
 *
 * @param array Wektor liczb ca³kowitych do posortowania.
 * @param left Indeks pocz¹tkowy zakresu do posortowania.
 * @param right Indeks koñcowy zakresu do posortowania.
 */
void MergeSort::mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2; ///< Obliczenie indeksu œrodkowego.

        mergeSort(array, left, middle); ///< Rekurencyjne sortowanie lewej po³owy.
        mergeSort(array, middle + 1, right); ///< Rekurencyjne sortowanie prawej po³owy.

        merge(array, left, middle, right); ///< Scalanie posortowanych po³ówek.
    }
}

/**
 * @brief Implementacja metody `merge`.
 *
 * Funkcja ³¹czy dwa posortowane podwektory w jeden wektor. Porównuje elementy
 * i kopiuje je w odpowiedniej kolejnoœci do oryginalnego wektora.
 *
 * @param array Wektor liczb ca³kowitych do posortowania.
 * @param left Indeks pocz¹tkowy pierwszego podwektora.
 * @param middle Œrodkowy indeks (koniec pierwszego podwektora).
 * @param right Indeks koñcowy drugiego podwektora.
 */
void MergeSort::merge(std::vector<int>& array, int left, int middle, int right) {
    // Tworzenie podwektorów z odpowiednimi elementami
    std::vector<int> leftArray(array.begin() + left, array.begin() + middle + 1);
    std::vector<int> rightArray(array.begin() + middle + 1, array.begin() + right + 1);

    int i = 0, j = 0, k = left; ///< Indeksy dla lewego, prawego i oryginalnego wektora.

    // Scalanie elementów z obu podwektorów
    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        }
        else {
            array[k++] = rightArray[j++];
        }
    }

    // Kopiowanie pozosta³ych elementów
    while (i < leftArray.size()) array[k++] = leftArray[i++];
    while (j < rightArray.size()) array[k++] = rightArray[j++];
}