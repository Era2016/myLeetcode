#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<int>& subs, int idx) {
        result.push_back(subs);
        for (int i = idx; i < nums.size(); i ++) {
            subs.push_back(nums[i]);
            backtrack(nums, subs, i+1);
            subs.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        vector<int> subs;
        backtrack(nums, subs, 0);
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    vector<vector<int>> result;

    auto print=[](vector<vector<int>>& result) {
        for (const auto& arr: result) {
            for (const auto& v: arr) {
                std::cout << v << "\t";
            }
            std::cout << std::endl;
        }
    };

    nums = {1,2,3};
    result = so->subsets(nums);
    print(result);
}
