#include <iostream>
#include <vector>
#include "MergeSort.h"

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    MergeSort::sort(arr);

    std::cout << "Posortowana tablica: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}