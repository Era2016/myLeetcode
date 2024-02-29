#include <iostream>
#include <vector>

using namespace std;

class Solution {
public :
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }

        int reach = 0;
        for (int i = 0; i <= reach && i < (int)nums.size(); ++ i) {
            reach = max(nums[i] + i, reach);
            //cout << "the current: "<< reach << endl;
        }

        return (reach < (int)nums.size() - 1) ? false : true;
    }

    /**
     *Dynamic Programming来解，我们维护一个一位数组dp，其中dp[i]表示走道i位置时剩余的最大步数，
     *那么递推公式为：dp[i] = max(dp[i - 1], A[i - 1]) - 1，
     *如果当某一个时刻dp数组的值为负了，说明无法抵达当前位置，则直接返回false，
     *最后我们判断dp数组最后一位是否为非负数即可知道是否能抵达该位置，
     */
    bool canJump_v2(int A[], int n) {
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1], A[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return dp[n - 1] >= 0;
    }
};

int main()
{
    Solution* so = new Solution();
    int arr[] = {2,3,1,1,4};
    //int arr[] = {3,2,1,0,4};

    bool result = so->canJump_v2(arr, 5);
    //vector<int> v(begin(arr), end(arr));
    //bool result = so->canJump(v);

    cout << result << endl;
}
