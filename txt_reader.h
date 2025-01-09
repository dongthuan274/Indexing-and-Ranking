#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

// Function để đọc data vào Vector
template <typename T>
void readFileToVector(const std::string& filename, std::vector<T>& vec) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        T num;
        if (iss >> num) {
            vec.push_back(num);
        }
    }

    file.close();
}