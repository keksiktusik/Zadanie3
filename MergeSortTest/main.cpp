#include <iostream>
#include <vector>
#include "pch.h"
#include "MergeSort.h"

int main() {
    MergeSort sorter;
    std::vector<int> array = { 5, 3, 8, 6, 2, 7, 4, 1 };

    std::cout << "Original array: ";
    for (int num : array) std::cout << num << " ";
    std::cout << std::endl;

    sorter.sort(array);

    std::cout << "Sorted array: ";
    for (int num : array) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}