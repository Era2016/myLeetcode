#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
    
        for (int i = 0; i <= n; i ++) dp[i][0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= amount; j ++) {
                if (j < coins[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    // 可以重复使用
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }

        return dp[n][amount];
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> coins;

    coins = {1, 2, 5};
    std::cout << so->change(5, coins) << std::endl; // 4

    coins = {2};
    std::cout << so->change(3, coins) << std::endl; // 0

    coins = {10};
    std::cout << so->change(10, coins) << std::endl; // 1
}
