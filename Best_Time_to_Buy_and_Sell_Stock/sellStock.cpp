#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 超时
    int maxProfit1(vector<int>& prices) {
    	int maxVal = 0;
    	int length = (int) prices.size();
        for (int i = 0; i < length; i ++) {
        	for (int j = i+1; j < length; j ++) {
				maxVal = max((prices[j]>prices[i])? (prices[j]-prices[i]): 0, maxVal);
        	}
        }
        return maxVal;
    }

    int maxProfit2(vector<int>& prices) {
    	int minPrice = INT_MAX;
    	int maxVal = 0;
    	for (int i = 0; i< (int) prices.size(); i ++) {
    		if (prices[i] < minPrice) {
    			minPrice = prices[i];
    		} else {
    			maxVal = max(maxVal, prices[i]-minPrice);
    		}
    	}
    	return maxVal;
    }

    // Kadane's Algorithm 通用算法
    // public int maxProfit(int[] prices) {
    //     int maxCur = 0, maxSoFar = 0;
    //     for(int i = 1; i < prices.length; i++) {
    //         maxCur = Math.max(0, maxCur += prices[i] - prices[i-1]);
    //         maxSoFar = Math.max(maxCur, maxSoFar);
    //     }
    //     return maxSoFar;
    // }
    
    int maxProfit(vector<int>& prices) {
    	int maxVal = 0;
    	int maxCur = 0;

    	for (int i = 1; i < (int) prices.size(); i ++) {
    		maxCur = max(0, maxCur+prices[i]-prices[i-1]);
    		maxVal = max(maxCur, maxVal);
    	}

    	return maxVal;
    }
};

int main() {
	vector<int> prices = {7,1,5,3,6,4};
	//vector<int> prices = {7,6,4,3,1};
	Solution* so = new Solution();
	cout << so->maxProfit(prices) << endl;
}