#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int rob(vector<int>& nums, int start, int end) {
        vector<int> dp(end+1, 0);
        dp[start] = nums[start];
        dp[start+1] = std::max(nums[start], nums[start+1]);
        for (int i = start+2; i <= end; i ++) {
            dp[i] = std::max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return std::max(nums[0], nums[1]);
        return std::max(rob(nums, 1, n-1), rob(nums, 0, n-2));
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {2,3,2};
    std::cout << so->rob(nums) << std::endl; // 3

    nums = {1,2,3,1};
    std::cout << so->rob(nums) << std::endl; // 4

    nums = {1,2,3};
    std::cout << so->rob(nums) << std::endl; // 3
}
