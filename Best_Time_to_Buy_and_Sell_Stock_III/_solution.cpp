#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // wrong answer
    int maxProfit(vector<int>& prices) {
        vector<int> v;
        int diff = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] >= prices[i-1]) {
                diff += prices[i]-prices[i-1];   
            } else {
                if (diff != 0) {
                    v.push_back(diff);
                    diff = 0;
                }
            }
        }

        if (diff != 0) {
            v.push_back(diff);
        }

        int size = v.size();
        if (size == 0) {
            return 0;
        } else if(size == 1) {
            return *v.begin();
        }
        sort(v.begin(), v.end());
        //cout << ">>>>>" << endl;
        //for (auto& val: v) {
        //    cout << val << " ";
        //}
        //cout << endl << "<<<<<" << endl;
        return *(v.end()-1) + *(v.end()-2);
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
