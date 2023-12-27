#include <iostream>
#include <vector>

/*
 *本题还可以使用二分查找将时间复杂度降低为 O(n log n)。
 *我们定义一个 dp 数组，其中 dp[k]存储长度为k+1的最长递增子序列的最后一个数字。
 *我们遍历每一个位置 i，如果其对应的数字大于dp数组中所有数字的值，
 *那么我们把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
 *如果我们发现这个数字在dp数组中比数字a大、比数字 b 小，则我们将b更新为此数字，使得之后构成递增序列的可能性增大。
 *以这种方式维护的dp数组永远是递增的，因此可以用二分查找加速搜索。
 */
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
            } else {
                auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
                *itr = nums[i];
            }
        }
        return dp.size();
    }
};
