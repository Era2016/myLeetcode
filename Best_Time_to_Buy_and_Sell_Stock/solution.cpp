#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxVal = 0;
        for (auto price :prices) {
            if (price < minPrice) minPrice = price;
            maxVal = std::max(maxVal, price-minPrice);
        }
        return maxVal;
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
