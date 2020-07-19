#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void print(vector<int> v);

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int length = (int) heights.size();
        if (length == 0) {
            return 0;
        }

        vector<int> lessFromLeft(length);  // 取当前height[i]的左边最小值
        vector<int> lessFromRight(length); // 取当前height[i]的右边最大值
        lessFromLeft[0] = 0;
        lessFromRight[length-1] = length-1;

        for (int i = 1; i < length; i ++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                //p --;
                p = lessFromLeft[p] - 1;
            }
            lessFromLeft[i] = p + 1;
        }

        for (int i = length-2; i >= 0; i --) {
            int p = i + 1;
            while (p <= length-1 && heights[p] >= heights[i]) {
                //p ++;
                p = lessFromRight[p] + 1;
            }
            lessFromRight[i] = p - 1;
        }

        int maxArea = 0;
        for (int i = 0; i < length; i ++) {
            maxArea = max(maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] + 1));
        }

        return maxArea;
    }

    // dp, 超时，复杂度太高
    int largestRectangleArea2(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
            
        // dp[i] 表示前i个最大值
        vector<int> dp((int)heights.size());
        //vector<int> dp;
        dp.push_back(heights[0]);
        int maxArea = heights[0];
           
        for (int i = 1; i < (int) heights.size(); i ++) {
            dp[i] = max(dp[i-1], maxAreaCurrentIndex(heights, i));
            if (dp[i] > maxArea) {
                maxArea = dp[i];
            }
        }

        return maxArea;
    }
private:
    int maxAreaCurrentIndex(vector<int> v, int index) {

        int mArea = 0;
        for (int i = 0; i < index; i ++) {
            int curArea = (index - i + 1) * minRangeHeight(v, i, index);
            //cout << "current index: "<< index << "\t i: "<< i << "\t area: " << curArea << endl;
            if (curArea > mArea) {
                mArea = curArea;
            }
        }

        return max(mArea, v[index]);
        //return mArea;
    }

    int minRangeHeight(vector<int> v, int start, int end) {
        int min = v[start];
        for (int i = start; i <= end; i ++) {
            if (v[i] < min) {
                min = v[i];
            }
        }

        return min;
    }
};

void print(vector<int> v) {
    cout << "current vector: ";
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter ++) {
        cout << *iter << "\t";
    }
    cout << endl;
}

int main() {
    vector<int> v = {2,1,5,6,2,3};
    //vector<int> v = {2,1,5,6};
    Solution* so = new Solution();
    //print(v); 
    int result = so->largestRectangleArea(v);
    cout << "result:" << result << endl;
    //cout << "result:" << so->largestRectangleArea(v) << endl;
}