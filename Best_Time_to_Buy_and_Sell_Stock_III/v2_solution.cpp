#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>> buy(n, vector<int>(k+1, 0));
        vector<vector<int>> sell(n, vector<int>(k+1, 0));

        for (int i = 1; i <= k; i ++) sell[0][i] = buy[0][i] = INT_MIN/2; // 初始值？？
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i < n; i ++) {
            buy[i][0] = std::max(sell[i-1][0]-prices[i], buy[i-1][0]); 
            for (int j =1; j <= k; j ++) {
                buy[i][j] = std::max(sell[i-1][j]-prices[i], buy[i-1][j]);
                sell[i][j] = std::max(buy[i-1][j-1]+prices[i], sell[i-1][j]);
            }
        }

        return *std::max_element(sell[n-1].begin(), sell[n-1].end());
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> prices;

    prices = {3,3,5,0,0,3,1,4};
    cout << so->maxProfit(prices) << endl;

    prices = {1,2,3,4,5};
    cout << so->maxProfit(prices) << endl;

    prices = {7,6,4,3,1};
    cout << so->maxProfit(prices) << endl;

    prices = {1,2,4,2,5,7,2,4,9,0};
    cout << so->maxProfit(prices) << endl;
}
