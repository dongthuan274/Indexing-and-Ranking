#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "sort.h"
#include "txt_reader.h"
#include "display.h"

int main() {
    std::vector<int> o_arr, o_brr, o_crr;

    // Đọc Vector từ File
    readFileToVector("arr.txt", o_arr);
    readFileToVector("brr.txt", o_brr);
    readFileToVector("crr.txt", o_crr);

    // In Mảng với index ban đầu
    displayWithIndexes(o_arr);
    displayWithIndexes(o_brr);
    displayWithIndexes(o_crr);

    std::vector<int> arr = o_arr, brr = o_brr, crr = o_crr;
    // Tạo Indexx cho mỗi mảng arr, brr, crr
    Indexx arrindex(arr);
    Indexx brrindex(brr);
    Indexx crrindex(crr);
    
    // Sắp xếp từng mảng arr, brr, crr và in ra các mảng còn lại được sắp xếp theo index của arr, brr, crr
    arrindex.sort(arr);
    printVector("Sorted arr: ", arr);
    printSortedAccordingToIndexes("Sorted brr according to arr sorted indexes: ", arrindex, o_brr);
    printSortedAccordingToIndexes("Sorted crr according to arr sorted indexes: ", arrindex, o_crr);

    brrindex.sort(brr);
    printVector("Sorted brr: ", brr);
    printSortedAccordingToIndexes("Sorted arr according to brr sorted indexes: ", brrindex, o_arr);
    printSortedAccordingToIndexes("Sorted crr according to brr sorted indexes: ", brrindex, o_crr);

    crrindex.sort(crr);
    printVector("Sorted crr: ", crr);
    printSortedAccordingToIndexes("Sorted arr according to crr sorted indexes: ", crrindex, o_arr);
    printSortedAccordingToIndexes("Sorted brr according to crr sorted indexes: ", crrindex, o_brr);

    // In ranks của từng phần tử trong từng mảng
    printRanks("Ranks for arr: ", arrindex);
    printRanks("Ranks for brr: ", brrindex);
    printRanks("Ranks for crr: ", crrindex);

    return 0;
}