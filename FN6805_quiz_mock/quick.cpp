#include <iostream>
#include <vector>

void findSubsetsHelper(const std::vector<int>& nums, int target, std::vector<int>& current, std::vector<std::vector<int>>& result, int start) {
    // Base case: if target is zero, we have found a valid subset
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // If we have processed all elements or target becomes negative, return
    if (start >= nums.size() || target < 0) {
        return;
    }

    // Include nums[start] in the current subset and recurse
    current.push_back(nums[start]);
    findSubsetsHelper(nums, target - nums[start], current, result, start + 1);

    // Exclude nums[start] from the current subset and recurse
    current.pop_back();
    findSubsetsHelper(nums, target, current, result, start + 1);
}

std::vector<std::vector<int>> findSubsetsWithSum(const std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    findSubsetsHelper(nums, target, current, result, 0);
    return result;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 11,13,21,31,33,35,37,41,43,51,53,55};
    int target = 255;

    std::vector<std::vector<int>> subsets = findSubsetsWithSum(nums, target);

    std::cout << "Subsets with sum " << target << ":\n";
    for (const auto& subset : subsets) {
        std::cout << "{ ";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "}\n";
    }

    std::cout<<"Number of subsets: "<<subsets.size()<<'\n';

    return 0;
}
