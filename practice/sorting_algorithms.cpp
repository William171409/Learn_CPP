#include "sorting_algorithms.hpp"
#include <utility>

namespace sorting_algorithms {
    void selection_sort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            std::swap(arr[i], arr[min_index]);
        }
    }
}
