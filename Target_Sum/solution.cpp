#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int num: nums) sum += num;
        
        if (sum<target || (sum-target)%2) return 0;
        int left = (sum-target)/2;
        vector<vector<int>> dp(n+1, vector<int>(left+1, 0));
        for (int i = 0; i <= n; i ++) dp[i][0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= left; j ++) {
                if (j < nums[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
            }
        }
        return dp[n][left];
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {1,1,1,1,1};
    std::cout << so->findTargetSumWays(nums, 3) << std::endl; // 5

    nums = {1};
    std::cout << so->findTargetSumWays(nums, 1) << std::endl; // 1

    nums = {1,0};
    std::cout << so->findTargetSumWays(nums, 1) << std::endl; // 2
    std::cout << so->findTargetSumWays(nums, 2) << std::endl; // 0

    nums = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    std::cout << so->findTargetSumWays(nums, 1000) << std::endl; // 0
}
