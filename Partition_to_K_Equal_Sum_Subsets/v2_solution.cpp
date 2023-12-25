#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
class Solution {
private:
    vector<int> nums;
    std::unordered_map<int, int> memo;    
    // 以桶视角，递归遍历每个桶，优先满足一个桶
    bool backtrack(int start, int target, int curSum, int k, int used) {
        if (k == 0) {
            return true;
        }
        
        if (curSum == target) {
            int res = backtrack(0, target, 0, k-1, used);
            memo[used] = res;
            return res;
        }
        
        if (memo.find(used) != memo.end()) {
            return memo[used];
        }

        for (int i = start; i < nums.size(); i ++) {
            if ((used >> i)&1 || nums[i]+curSum>target) {
                continue;
            }
            curSum += nums[i];
            used |= 1 << i;
            if (backtrack(i+1, target, curSum, k, used)) {
                return true;
            }
            curSum -= nums[i];
            used ^= 1 << i;
        }
        return false;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k > nums.size()) return false;
        
        int sum = 0;
        for (const auto& n: nums) sum += n;
        if (sum%k != 0) return false;

        int target = sum/k;
        //vector<bool> used(k+1, false);
        int used = 0;
        this->nums = nums;
        return backtrack(0, target, 0, k, used);
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {4,3,2,3,5,2,1};
    std::cout << so->canPartitionKSubsets(nums, 4) << std::endl;

    nums = {1,2,3,4};
    std::cout << so->canPartitionKSubsets(nums, 3) << std::endl;

    nums = {3,2,1,3,6,1,4,8,10,8,9,1,7,9,8,1};
    std::cout << so->canPartitionKSubsets(nums, 9) << std::endl;
}
