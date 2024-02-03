#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int cnt;
    void backtrack(vector<int>& nums, int target, int idx) {
        if (idx == nums.size()) {
            if (0 == target) {
                cnt ++;
            }
            return;
        }

        //for (int i = idx; i < nums.size(); i ++) {
        //    backtrack(nums, target-nums[i], i+1);
        //    backtrack(nums, target+nums[i], i+1);
        //}
        backtrack(nums, target-nums[idx], idx+1);
        backtrack(nums, target+nums[idx], idx+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        this->cnt = 0;
        backtrack(nums, target, 0);
        return this->cnt;
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
