#include <climits>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (dp[i-1] >= 0) {
                dp[i] = dp[i-1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
            maxSum = std::max(maxSum, dp[i]);
        } 
        return maxSum;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    //std::cout << so->maxSubArray(nums) << std::endl;
    assert(so->maxSubArray(nums) == 6);

    nums = {1};
    assert(so->maxSubArray(nums) == 1);

    nums = {5,4,-1,7,8};
    assert(so->maxSubArray(nums) == 23);
}
