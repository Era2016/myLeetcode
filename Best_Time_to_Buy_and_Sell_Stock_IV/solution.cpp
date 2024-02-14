#include <algorithm>
#include <climits>
#include <iostream>
#include <ratio>
#include <vector>

using std::vector;
class Solution {
public:
    /**
     * buy[i][j] = max(sell[i-1][j]-prices[i], buy[i-1][j])
     * sell[i][j] = max(buy[i-1][j-1]+prices[i], sell[i-1][j])
     * */
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = std::min(k, n/2);
        vector<vector<int>> buy(n, vector<int>(k+1, 0));
        vector<vector<int>> sell(n, vector<int>(k+1, 0));

        for (int j = 1; j <= k; j ++) sell[0][j] = buy[0][j] = INT_MIN/2;
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i < n; i ++) {
            buy[i][0] = std::max(sell[i-1][0]-prices[i], buy[i-1][0]);
            for (int j = 1; j <= k; j ++) {
                buy[i][j] = std::max(sell[i-1][j]-prices[i], buy[i-1][j]);
                sell[i][j] = std::max(buy[i-1][j-1]+prices[i], sell[i-1][j]);
            }
        }

        return *std::max_element(sell[n-1].begin(), sell[n-1].end());
    }
    /**
     * buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
     * buy[1][0] = buy[0][0], sell[0][0]-prices[1] = max{-prices[0], -prices[1]};
     * buy[2][0] = buy[1][0], sell[1][0]-prices[2] = max{-prices[0], -prices[1], -prices[2]}
     * */
};

int main() {
    Solution *so = new Solution();
    vector<int> prices;

    prices = {2,4,1};
    std::cout << so->maxProfit(2, prices) << std::endl;

    prices = {3,2,6,5,0,3};
    std::cout << so->maxProfit(2, prices) << std::endl; // 7
}

