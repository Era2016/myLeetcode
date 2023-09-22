#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
class Solution {
public:
    // 定义dp[i]为以第i个数字结尾的最长上升子序列的长度，注意nums[i]必须被选取
    // dp[i] = max(dp[j])+1  0<=j<i and nums[j]<nums[i]
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {10,9,2,5,3,7,101,18};
    assert(so->lengthOfLIS(nums) == 4);

    nums = {0,1,0,3,2,3};
    assert(so->lengthOfLIS(nums) == 4);
    
    nums = {7,7,7,7,7,7,7};
    assert(so->lengthOfLIS(nums) == 1);

    nums = {}; 
    assert(so->lengthOfLIS(nums) == 0);

    nums = {1}; 
    assert(so->lengthOfLIS(nums) == 1);
}
