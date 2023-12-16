#include <functional>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    // 递归遍历nums中的每个数字    
    bool backtrack_v1(vector<int>& nums, int target, int idx, vector<int>& kArr) {
        if (idx == nums.size()) {
            // check
            for (int i = 0; i < kArr.size(); i ++) {
                if (kArr[i] != target) {
                    return false;
                }
            }
            return true;
        }

        // 遍历nums[idx]可能装入的桶
        for (int i = 0; i < kArr.size(); i ++) {
            if (nums[idx]+kArr[i] > target) {
                continue;
            }
            kArr[i] += nums[idx];
            if (backtrack_v1(nums, target, idx+1, kArr)) {
                return true;
            }
            kArr[i] -= nums[idx];
        }
        // nums[idx]哪个桶都无法装入
        return false;
    }

    bool backtrack_v2(vector<int>& nums, int target, int idx, vector<int>& kArr, vector<bool>& used) {
        if (idx == kArr.size()) {
            for (int i = 0; i < kArr.size(); i ++) {
                if (kArr[i] == target) return false;
            }
            return true;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (used[nums[i]] || kArr[idx]+nums[i] > target) {
                continue;
            }
            
            kArr[idx] += nums[i];
            used[nums[i]] = true;
            if (backtrack_v2(nums, target, idx+1, kArr, used)) {
                return true;
            }
            kArr[idx] -= nums[i];
            used[nums[i]] = false;
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
        vector<int> kArr(k);
        sort(nums.begin(), nums.end(), std::greater<int>()); 
        return backtrack_v1(nums, target, 0, kArr);
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {4,3,2,3,5,2,1};
    std::cout << so->canPartitionKSubsets(nums, 4) << std::endl;

    nums = {1,2,3,4};
    std::cout << so->canPartitionKSubsets(nums, 3) << std::endl;
}
