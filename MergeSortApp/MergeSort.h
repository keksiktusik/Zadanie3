#pragma once
#include <vector>

class MergeSort {
public:
    static void sort(std::vector<int>& arr); // funkcja sortuj¹ca
private:
    static void mergeSort(std::vector<int>& arr, int left, int right); // funkcja pomocnicza
    static void merge(std::vector<int>& arr, int left, int mid, int right); // scalanie
};
