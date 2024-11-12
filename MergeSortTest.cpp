#include "MergeSort.h"
#include <gtest/gtest.h>

TEST(MergeSortTest, SortedArrayRemainsUnchanged) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, ReverseSortedArray) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, RandomArray) {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9}));
}

TEST(MergeSortTest, AllNegativeNumbers) {
    std::vector<int> arr = {-5, -3, -1, -2, -4};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-5, -4, -3, -2, -1}));
}

TEST(MergeSortTest, MixedNegativeAndPositiveNumbers) {
    std::vector<int> arr = {-3, -1, 2, 0, -2, 1, 3};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-3, -2, -1, 0, 1, 2, 3}));
}

TEST(MergeSortTest, EmptyArray) {
    std::vector<int> arr;
    MergeSort::sort(arr);
    EXPECT_EQ(arr, std::vector<int>{});
}

TEST(MergeSortTest, SingleElementArray) {
    std::vector<int> arr = {42};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{42}));
}

TEST(MergeSortTest, ArrayWithDuplicates) {
    std::vector<int> arr = {3, 1, 4, 1, 5, 1};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 1, 1, 3, 4, 5}));
}

TEST(MergeSortTest, AllNegativeWithDuplicates) {
    std::vector<int> arr = {-3, -1, -1, -2, -3};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-3, -3, -2, -1, -1}));
}

TEST(MergeSortTest, MixedPositiveNegativeWithDuplicates) {
    std::vector<int> arr = {3, -1, -1, 0, 2, -3, 3};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-3, -1, -1, 0, 2, 3, 3}));
}

TEST(MergeSortTest, TwoElements) {
    std::vector<int> arr = {2, 1};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2}));
}

TEST(MergeSortTest, LargeArray) {
    std::vector<int> arr(150, 1);
    arr[0] = -1;
    arr[1] = 100;
    MergeSort::sort(arr);
    EXPECT_EQ(arr.front(), -1);
    EXPECT_EQ(arr.back(), 100);
}

TEST(MergeSortTest, LargeArrayWithMixedNumbers) {
    std::vector<int> arr = {2, -3, 4, -1, 0, 5, -2, 1, 3};
    arr.insert(arr.end(), 110, 0); // add duplicates of 0
    MergeSort::sort(arr);
    EXPECT_EQ(arr.front(), -3);
    EXPECT_EQ(arr.back(), 5);
}