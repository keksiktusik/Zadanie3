#include "pch.h"
#include "gtest/gtest.h"
#include "MergeSort.h"
#include <vector>

TEST(MergeSortTest, AlreadySortedArray) {
    MergeSort sorter;
    std::vector<int> array = { 1, 2, 3, 4, 5 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, ReverseSortedArray) {
    MergeSort sorter;
    std::vector<int> array = { 5, 4, 3, 2, 1 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, RandomArray) {
    MergeSort sorter;
    std::vector<int> array = { 4, 2, 7, 3, 1 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{1, 2, 3, 4, 7}));
}

TEST(MergeSortTest, NegativeNumbers) {
    MergeSort sorter;
    std::vector<int> array = { -5, -2, -3, -1 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{-5, -3, -2, -1}));
}

TEST(MergeSortTest, MixedNumbers) {
    MergeSort sorter;
    std::vector<int> array = { -3, 2, -1, 4 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{-3, -1, 2, 4}));
}

TEST(MergeSortTest, EmptyArray) {
    MergeSort sorter;
    std::vector<int> array;
    sorter.sort(array);
    EXPECT_EQ(array, std::vector<int>{});
}

TEST(MergeSortTest, SingleElementArray) {
    MergeSort sorter;
    std::vector<int> array = { 1 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{1}));
}

TEST(MergeSortTest, ArrayWithDuplicates) {
    MergeSort sorter;
    std::vector<int> array = { 4, 2, 4, 2 };
    sorter.sort(array);
    EXPECT_EQ(array, (std::vector<int>{2, 2, 4, 4}));
}