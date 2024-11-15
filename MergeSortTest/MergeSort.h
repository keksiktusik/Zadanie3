#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort {
public:
    void sort(std::vector<int>& array);

private:
    void mergeSort(std::vector<int>& array, int left, int right);
    void merge(std::vector<int>& array, int left, int middle, int right);
};

#endif // MERGESORT_H