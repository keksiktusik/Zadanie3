#include "gtest/gtest.h"
#include "MergeSort.h"
#include <vector>

TEST(MergeSortTests, AlreadySortedArray) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTests, ReverseSortedArray) {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTests, RandomArray) {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 1, 2, 3, 4, 5, 6, 9}));
}

TEST(MergeSortTests, NegativeNumbers) {
    std::vector<int> arr = { -3, -1, -4, -1, -5, -9, -2, -6 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-9, -6, -5, -4, -3, -2, -1, -1}));
}

TEST(MergeSortTests, MixedNumbers) {
    std::vector<int> arr = { 3, -1, 4, -1, 5, 9, -2, 6 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-2, -1, -1, 3, 4, 5, 6, 9}));
}

TEST(MergeSortTests, EmptyArray) {
    std::vector<int> arr = {};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{}));
}

TEST(MergeSortTests, SingleElementArray) {
    std::vector<int> arr = { 42 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{42}));
}

TEST(MergeSortTests, DuplicateElementsArray) {
    std::vector<int> arr = { 3, 3, 1, 4, 4, 5, 9, 2, 6, 6 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 3, 4, 4, 5, 6, 6, 9}));
}

TEST(MergeSortTests, LargeArray) {
    std::vector<int> arr(150, 1);
    for (int i = 0; i < 150; i++) arr[i] = rand() % 100 - 50;
    MergeSort::sort(arr);

    bool is_sorted = true;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            is_sorted = false;
            break;
        }
    }
    EXPECT_TRUE(is_sorted);
}