#include "MergeSort.h"
#include "pch.h"

void MergeSort::sort(std::vector<int>& array) {
    if (array.empty()) return; // Obs³uga pustej tablicy
    mergeSort(array, 0, array.size() - 1);
}

void MergeSort::mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

void MergeSort::merge(std::vector<int>& array, int left, int middle, int right) {
    std::vector<int> leftArray(array.begin() + left, array.begin() + middle + 1);
    std::vector<int> rightArray(array.begin() + middle + 1, array.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        }
        else {
            array[k++] = rightArray[j++];
        }
    }

    while (i < leftArray.size()) array[k++] = leftArray[i++];
    while (j < rightArray.size()) array[k++] = rightArray[j++];
}