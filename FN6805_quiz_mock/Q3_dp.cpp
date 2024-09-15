#include <vector>
#include <iostream>

int NumberPayments(int sum, int c1, int c2, int c3) {
    // Create a dp array initialized with 0
    std::vector<int> dp(sum + 1, 0);
    
    // Base case: There's one way to make sum 0 (by using no coins)
    dp[0] = 1;
    
    // Array of the coin values
    std::vector<int> coins = {c1, c2, c3};
    
    // Iterate over each coin value
    for (int coin : coins) {
        // For each coin, update dp for sums that can include this coin
        for (int i = coin; i <= sum; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    
    // The result is the number of ways to form 'sum'
    return dp[sum];
}

int main() {
    // Test cases
    std::cout << "Number of ways to pay 5 with coins 1, 2, 3: " << NumberPayments(5, 1, 2, 3) << std::endl;
    std::cout << "Number of ways to pay 10 with coins 2, 3, 5: " << NumberPayments(10, 2, 3, 5) << std::endl;

    return 0;
}
