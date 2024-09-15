#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

void printCommonCount(const std::set<int>& setA, const std::set<int>& setB, const std::string& label) {
    std::set<int> commonSet;
    
    // Find intersection of setA and setB and store it in commonSet
    std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                          std::inserter(commonSet, commonSet.begin()));

    // Output the result
    std::cout << label << ": " << commonSet.size() << std::endl;
}

int main() {
    // Initialize the sets
    std::set<int> set1 = {1, 2, 3, 4, 5};
    std::set<int> set2 = {2, 3, 4, 5, 7};
    std::set<int> set3 = {3, 8, 9, 7, 6};

    // Compare each pair of sets
    printCommonCount(set1, set2, "1-2");
    printCommonCount(set1, set3, "1-3");
    printCommonCount(set2, set3, "2-3");

    return 0;
}
