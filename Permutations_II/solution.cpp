#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<int>& permu, vector<bool>& used) {
        if (permu.size() == nums.size()) {
            result.push_back(permu);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (used[i]) continue;
            // 如果前面的相邻相等元素没有用过，则跳过
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            permu.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, permu, used);
            permu.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        vector<int> permu;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, permu, used);
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    vector<vector<int>> result;

    auto print=[](vector<vector<int>>& result) {
        for (const auto& arr: result) {
            for (const auto& val: arr) {
                std::cout << val << "\t";
            }
            std::cout << std::endl; 
        }
        std::cout << std::endl; 
    };
    nums = {1,1,2};
    result = so->permuteUnique(nums);
    print(result);

    nums = {1,2,3};
    result = so->permuteUnique(nums);
    print(result);

    nums = {0,0,0,1,2};
    result = so->permuteUnique(nums);
    print(result);
}
