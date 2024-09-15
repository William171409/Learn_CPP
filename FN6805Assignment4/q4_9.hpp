#pragma once
#include <vector>
const int sudoku_sum{45};
const std::vector<std::vector<int>> sudoku = {
    {8, 9, 5, 7, 4, 1, 6, 2, 3},
    {2, 4, 3, 9, 5, 6, 8, 1, 7},
    {7, 6, 1, 8, 2, 3, 4, 9, 5},
    {9, 3, 4, 6, 7, 5, 1, 8, 2},
    {6, 1, 7, 2, 9, 8, 5, 3, 4},
    {5, 8, 2, 3, 1, 4, 9, 7, 6},
    {3, 5, 9, 1, 6, 2, 7, 4, 8},
    {1, 2, 6, 4, 8, 7, 3, 5, 9},
    {4, 7, 8, 5, 3, 9, 2, 6, 1}
};

void q4_9(const std::vector<std::vector<int>> &sudoku, int sudoku_sum);
