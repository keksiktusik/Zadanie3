#include <iostream>
#include "MergeSort.h"

int main() {

std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    MergeSort::sort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;

}