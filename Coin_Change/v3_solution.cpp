#include <climits>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    void print(vector<int>& coins) {
        for (auto coin: coins) {
            std::cout << coin << " ";
        }
        std::cout << std::endl;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i ++) {
            for (const auto& coin: coins) {
                if (i >= coin) {
                    dp[i] = std::min(dp[i], dp[i-coin]+1);
                }
            }
        }
        //print(dp);
        return dp[amount] == INT_MAX-1? -1: dp[amount];
    }
};

int main() {
    Solution* so = new Solution();
    vector<int> v;

    v = {1,2,5};
    std::cout << so->coinChange(v, 11) << std::endl;

    v = {1,7,10};
    std::cout << so->coinChange(v, 14) << std::endl;

    clock_t start,end;
    start = clock();
    v = {411,412,413,414,415,416,417,418,419,420,421,422};
    std::cout << so->coinChange(v, 9864) << std::endl; // timeout
    end = clock();
    std::cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<< std::endl;
}
