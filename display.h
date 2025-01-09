#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "sort.h"

// Function để in Mảng với số index từng phần tử ban đầu
void displayWithIndexes(const std::vector<int>& arr);

// Function để in Vector
template <typename T>
void printVector(const std::string& message, const std::vector<T>& vec) {
    std::cout << message;
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Function để in Vector được sắp xếp theo Index mới thêm vào
template <typename T>
void printSortedAccordingToIndexes(const std::string& message, const Indexx& indexx, const std::vector<T>& vec) {
    std::cout << message;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << indexx.el(vec, i) << " ";
    }
    std::cout << std::endl;
}

// Function để in Rank của từng phần tử trong mảng
void printRanks(const std::string& message, Indexx& indexx);