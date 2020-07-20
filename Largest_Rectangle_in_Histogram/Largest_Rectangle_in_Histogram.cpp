#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void print(vector<int> v);

class Solution {
public:
    // TODO 性能比方法2要好，原因未知
    int largestRectangleArea(vector<int>& heights) {
        
        int length = (int) heights.size();
        if (length == 0) {
            return 0;
        }

        // 以下两个数组里，i是左/右边最大的值，但不包含，所以后面计算宽度时要减去2
        vector<int> lessFromLeft(length);  // 取当前height[i]的左边最小值，不包含
        vector<int> lessFromRight(length); // 取当前height[i]的右边最大值，不包含
        lessFromLeft[0] = -1;
        lessFromRight[length-1] = length;

        for (int i = 1; i < length; i ++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                //p --;
                p = lessFromLeft[p];
            }
            lessFromLeft[i] = p;
        }

        for (int i = length-2; i >= 0; i --) {
            int p = i + 1;
            while (p <= length-1 && heights[p] >= heights[i]) {
                //p ++;
                p = lessFromRight[p];
            }
            lessFromRight[i] = p;
        }

        int maxArea = 0;
        for (int i = 0; i < length; i ++) {
            maxArea = max(maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        }

        return maxArea;
    }

    int largestRectangleArea2(vector<int>& heights) {

        int length = (int) heights.size();
        if (length == 0) {
            return 0;
        }

        vector<int> lessFromLeft(length);  // 取当前height[i]的左边最小值，包含
        vector<int> lessFromRight(length); // 取当前height[i]的右边最大值，包含
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

    // AC自动机算法
    int largestRectangleArea3(vector<int>& heights) {

        int maxArea = 0;
        vector<int> hIndex;     // heights的索引，起到heights value递增作用
        heights.push_back(0);   // heights sentinel

        for (int i = 0; i < (int) heights.size(); i ++) {
            while(hIndex.size() > 0 && heights[hIndex.back()] > heights[i]) {
                int curHight = heights[hIndex.back()];
                hIndex.pop_back();
                
                int l = (hIndex.size() > 0) ? hIndex.back(): -1;
                maxArea = max(maxArea, curHight * (i - l - 1));
            }
            hIndex.push_back(i);
        }

        heights.pop_back();
        return maxArea;
    }

    // dp, 超时，复杂度太高
    int largestRectangleArea4(vector<int>& heights) {
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
    int result = so->largestRectangleArea3(v);
    cout << "result:" << result << endl;
    //cout << "result:" << so->largestRectangleArea(v) << endl;
}