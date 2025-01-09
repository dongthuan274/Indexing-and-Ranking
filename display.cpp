#include <iostream>
#include <vector>
#include <algorithm>
#include "sort.h"
#include "display.h"

// Function để in Mảng với số index từng phần tử ban đầu
void displayWithIndexes(const std::vector<int>& arr) {
    std::cout << "Original array with indexes: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "(" << i << ": " << arr[i] << ") ";
    }
    std::cout << std::endl;
}

// Function để in Rank của từng phần tử trong mảng
void printRanks(const std::string& message, Indexx& indexx) {
    std::vector<int> ranks(indexx.n);
    indexx.rank(ranks);
    std::cout << message;
    for (const auto& rank : ranks) {
        std::cout << rank + 1 << " ";
    }
    std::cout << std::endl;
}