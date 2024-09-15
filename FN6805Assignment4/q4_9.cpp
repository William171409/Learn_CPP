#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool check_sum(const std::vector<int> &v, int expected_sum) {
  return std::accumulate(v.begin(), v.end(), 0) == expected_sum;
}

void print_rows(const std::vector<std::vector<int>> &sudoku) {
  std::cout << "Rows:\n";
  std::for_each(sudoku.begin(), sudoku.end(), [](const std::vector<int> &row) {
    std::for_each(row.begin(), row.end(),
                  [](int num) { std::cout << num << " "; });
    std::cout << std::endl;
  });
}

void print_columns(const std::vector<std::vector<int>> &sudoku) {
  std::cout << "Columns:\n";
  for (int i = 0; i < 9; ++i) {
    std::for_each(
        sudoku.begin(), sudoku.end(),
        [i](const std::vector<int> &row) { std::cout << row[i] << " "; });
    std::cout << std::endl;
  }
}

void print_subsquares(const std::vector<std::vector<int>> &sudoku) {
  std::cout << "3x3 Subsquares:\n";
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      for (int x = i; x < i + 3; ++x) {
        std::for_each(sudoku[x].begin() + j, sudoku[x].begin() + j + 3,
                      [](int num) { std::cout << num << " "; });
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
  }
}

bool check_rows(const std::vector<std::vector<int>> &sudoku, int expected_sum) {
  return std::all_of(sudoku.begin(), sudoku.end(),
                     [=](const std::vector<int> &row) {
                       return check_sum(row, expected_sum);
                     });
}

bool check_columns(const std::vector<std::vector<int>> &sudoku,
                   int expected_sum) {
  for (int i = 0; i < 9; ++i) {
    std::vector<int> col(9);
    std::transform(sudoku.begin(), sudoku.end(), col.begin(),
                   [=](const std::vector<int> &row) { return row[i]; });
    if (!check_sum(col, expected_sum)) {
      return false;
    }
  }
  return true;
}

bool check_squares(const std::vector<std::vector<int>> &sudoku,
                   int expected_sum) {
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      std::vector<int> square;
      for (int x = i; x < i + 3; ++x)
        square.insert(square.end(), sudoku[x].begin() + j,
                      sudoku[x].begin() + j + 3);
      if (!check_sum(square, expected_sum)) {
        return false;
      }
    }
  }
  return true;
}

bool check_consistency(const std::vector<std::vector<int>> &sudoku,
                       int expected_sum) {

  auto rows_valid = check_rows(sudoku, expected_sum);
  auto cols_valid = check_columns(sudoku, expected_sum);
  auto subsquares_valid = check_squares(sudoku, expected_sum);
  return rows_valid && cols_valid && subsquares_valid;
}

void q4_9(const std::vector<std::vector<int>> &sudoku, int sudoku_sum) {
  print_rows(sudoku);
  std::cout << std::endl;
  print_columns(sudoku);
  std::cout << std::endl;
  print_subsquares(sudoku);
  std::cout << std::endl;

  if (check_consistency(sudoku, sudoku_sum)) {
    std::cout << "All sums are consistent with " << sudoku_sum << ".\n";
  } else {
    std::cout << "Sums are inconsistent.\n";
  }
}
