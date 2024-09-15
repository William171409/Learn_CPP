#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

bool is_strictly_sorted1(const std::vector<int>& v) {
  if (v.size() < 2) return true;
  return std::adjacent_find(v.begin(), v.end(), [](const int a, const int b){return a >= b;}) == v.end();
}


bool is_strictly_sorted2(const std::vector<int>& v) {
  if (v.size() < 2) return true;

  std::vector<bool> is_less_than_next(v.size() - 1);
  std::transform(v.begin(), v.end() - 1, v.begin() + 1, is_less_than_next.begin(),
                 [](const int current, const int next) { return current < next; });

  return std::all_of(is_less_than_next.begin(), is_less_than_next.end(), [](bool x) { return x; });
}

void q5_5() {
    std::vector<int> sorted_vector = {1, 2, 3, 4, 5};
    std::vector<int> unsorted_vector = {1, 3, 2, 4, 5};
    std::vector<int> single_element_vector = {1};

    std::cout << "sorted: " << (is_strictly_sorted1(sorted_vector) ? "Passed" : "Failed") << '\n';
    std::cout << "unsorted: " << (is_strictly_sorted1(unsorted_vector) ? "Passed" : "Failed") << '\n';
    std::cout << "single element: " << (is_strictly_sorted1(single_element_vector) ? "Passed" : "Failed") << '\n';

    std::cout << "sorted: " << (is_strictly_sorted2(sorted_vector) ? "Passed" : "Failed") << '\n';
    std::cout << "unsorted: " << (is_strictly_sorted2(unsorted_vector) ? "Passed" : "Failed") << '\n';
    std::cout << "single element: " << (is_strictly_sorted2(single_element_vector) ? "Passed" : "Failed") << '\n';
}
