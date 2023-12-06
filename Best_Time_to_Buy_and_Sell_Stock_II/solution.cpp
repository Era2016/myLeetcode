#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];
        int lastPrice = prices[0];
        int maxProf = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (currMin > prices[i]) {
                maxProf += lastPrice-currMin;
                currMin = prices[i];
                lastPrice = prices[i];
            }

            if(prices[i] > lastPrice) {
                lastPrice = prices[i];
            } else  {
                maxProf += lastPrice-currMin;
                currMin = prices[i];
                lastPrice = prices[i];
            }
        }
        if (lastPrice != currMin) {
            maxProf += lastPrice-currMin;
        }
        return maxProf;
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
