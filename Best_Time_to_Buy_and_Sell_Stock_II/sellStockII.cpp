#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
  		int maxVal = 0;
  		int curMax = 0;
  		for (int i = 1; i < (int) prices.size(); i ++) {
  			if (prices[i] >= prices[i-1]) {
  				curMax = curMax + prices[i] - prices[i-1];
  			} else {
  				maxVal += curMax;
  				curMax = 0;
  			}
  		}

  		maxVal += curMax;
  		return maxVal;
    }

    // 改进版，代码精简下
    int maxProfit2(vector<int>& prices) {
  		int maxVal = 0;
  		for (int i = 1; i < (int) prices.size(); i ++) {
  			if (prices[i] >= prices[i-1]) {
  				maxVal += prices[i] - prices[i-1];
  			}
  		}

  		return maxVal;
    }
};

int main() {
	vector<int> prices = {7,1,5,3,6,4};
	//vector<int> prices = {1,2,3,4,5};
	//vector<int> prices = {7,6,4,3,1};
	Solution* so = new Solution();
	cout << so->maxProfit(prices) << endl;
}