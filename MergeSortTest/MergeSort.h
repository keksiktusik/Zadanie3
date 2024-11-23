/**
 * @file MergeSort.h
 * @brief Definicja klasy MergeSort implementuj¹cej algorytm sortowania przez scalanie (Merge Sort).
 *
 * Ten plik nag³ówkowy zawiera deklaracjê klasy MergeSort oraz jej metod publicznych i prywatnych.
 * Klasa zapewnia funkcjê sortowania wektorów liczb ca³kowitych w kolejnoœci rosn¹cej.
 */
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>///< U¿ywane do reprezentacji dynamicznych tablic (wektorów).

 /**
  * @class MergeSort
  * @brief Klasa implementuj¹ca algorytm sortowania przez scalanie.
  *
  * Klasa zawiera publiczn¹ metodê `sort` do sortowania wektorów oraz metody prywatne
  * `mergeSort` i `merge`, które realizuj¹ rekurencyjny podzia³ oraz scalanie posortowanych fragmentów.
  */
class MergeSort {
public:
    /**
   * @brief Sortuje podany wektor liczb ca³kowitych w kolejnoœci rosn¹cej.
   *
   * Funkcja wywo³uje metodê rekurencyjn¹ `mergeSort`, aby posortowaæ przekazany wektor.
   *
   * @param array Wektor liczb ca³kowitych do posortowania.
   */
    void sort(std::vector<int>& array);

private:
    /**
    * @brief Funkcja rekurencyjna dziel¹ca tablicê na mniejsze czêœci.
    *
    * Funkcja dzieli tablicê na dwie po³owy i rekurencyjnie sortuje ka¿d¹ z nich.
    * Nastêpnie ³¹czy posortowane czêœci za pomoc¹ funkcji `merge`.
    *
    * @param array Wektor liczb ca³kowitych do posortowania.
    * @param left Indeks pocz¹tkowy podwektora.
    * @param right Indeks koñcowy podwektora.
    */
    void mergeSort(std::vector<int>& array, int left, int right);
    /**
     * @brief £¹czy dwa posortowane podwektory w jeden posortowany wektor.
     *
     * Funkcja porównuje elementy z dwóch podwektorów i kopiuje je w odpowiedniej kolejnoœci
     * do oryginalnego wektora. Pozosta³e elementy s¹ kopiowane po przetworzeniu jednego z podwektorów.
     *
     * @param array Wektor liczb ca³kowitych do posortowania.
     * @param left Indeks pocz¹tkowy pierwszego podwektora.
     * @param middle Indeks koñcowy pierwszego podwektora (pocz¹tek drugiego).
     * @param right Indeks koñcowy drugiego podwektora.
     */
    void merge(std::vector<int>& array, int left, int middle, int right);
};

#endif // MERGESORT_H