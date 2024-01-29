#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        std::for_each(nums.begin(), nums.end(), [&sum](int cnt) {
                sum += cnt;
                });
        if (sum % 2) return false;

        int n = nums.size();
        int w = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
        for (int i = 0; i < n+1; i ++) dp[i][0] = true;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= w; j ++) {
                if (j < nums[i-1]) {
                    // 背包容量不足，不能装入第 i 个物品
                    dp[i][j] = dp[i-1][j];
                } else {
                    // 装入或不装入背包
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][w];
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {1,5,11,5};
    std::cout << so->canPartition(nums) << std::endl;

    nums = {1,2,3,5};
    std::cout << so->canPartition(nums) << std::endl;
}
