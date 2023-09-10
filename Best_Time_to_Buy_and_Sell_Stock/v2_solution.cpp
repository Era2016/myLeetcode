#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        vector<vector<int>> dp(length, vector<int>(2, 0));
        for (int i = 0; i < length; i ++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = std::max(dp[i-1][1], -prices[i]);
        }

        return dp[length-1][0];
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> prices;

    prices = {7,1,5,3,6,4};
    std::cout << so->maxProfit(prices) << std::endl;

    prices = {7,6,4,3,1};
    std::cout << so->maxProfit(prices) << std::endl;
}
