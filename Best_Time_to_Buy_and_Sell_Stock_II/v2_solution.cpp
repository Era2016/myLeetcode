#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // 贪心算法
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }

	/**
	动态规划
	定义状态 dp[i][0]表示第i天交易完后手里没有股票的最大利润,
			dp[i][1]表示第i天交易完后手里持有一支股票的最大利润（i从0开始）
	*/
	int maxProfit_v2(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }

    // 动态规划--优化后
	int maxProfit_v3(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp1, dp0 - prices[i]);
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> prices;

    prices = {7,1,5,3,6,4};
    cout << so->maxProfit(prices) << endl;

    prices = {1,2,3,4,5};
    cout << so->maxProfit(prices) << endl;

    prices = {7,6,4,3,1};
    cout << so->maxProfit(prices) << endl;
}
