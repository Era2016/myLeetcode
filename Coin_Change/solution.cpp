#include <iostream>
#include <vector>

using std::vector;

class Solution {
private:
    vector<int> memo;
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (memo[amount] != -2) {
            return memo[amount];
        }
        int res = INT_MAX;
        for (auto coin: coins) {
            int sub = dp(coins, amount-coin);
            if (sub == -1) continue;

            res = std::min(res, sub+1);
        }

        memo[amount] = (res==INT_MAX)? -1: res;
        return memo[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int>(amount+1, -2);
        return this->dp(coins, amount);
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> coins;

    coins = {1,2,5};
    std::cout << so->coinChange(coins, 11) << std::endl;

    coins = {2};
    std::cout << so->coinChange(coins, 3) << std::endl;

    coins = {1};
    std::cout << so->coinChange(coins, 0) << std::endl;
}
