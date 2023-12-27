#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
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