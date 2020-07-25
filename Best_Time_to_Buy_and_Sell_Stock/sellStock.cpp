#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 超时
    int maxProfit1(vector<int>& prices) {
    	int maxVal = 0;
    	int length = (int) prices.size();
        for (int i=0; i<length; i ++) {
        	for (int j=i+1; j<length; j ++) {
				maxVal = max((prices[j]>prices[i])? (prices[j]-prices[i]):0, maxVal);
        	}
        }
        return maxVal;
    }

    int maxProfit(vector<int>& prices) {
    	
    }
};

int main() {
	vector<int> prices = {7,1,5,3,6,4};
	//vector<int> prices = {7,6,4,3,1};
	Solution* so = new Solution();
	cout << so->maxProfit(prices) << endl;
}