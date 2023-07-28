#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<int>& subset, int idx) {
        result.push_back(subset);
        for (int i = idx; i < nums.size(); i ++) {
            if (i != idx && nums[i] == nums[i-1]) {
                continue;
            }

            subset.push_back(nums[i]);
            backtrack(nums, subset, i+1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, subset, 0);
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> subset;
    vector<vector<int>> result;

    auto print=[](vector<vector<int>>& result) {
        for (const auto& arr: result) {
            for (const auto& v: arr) {
                std::cout << v << "\t";
            }
            std::cout << std::endl;
        }
    };

    subset = {1,2,2};
    result = so->subsetsWithDup(subset);
    print(result);

    subset = {0}; 
    result = so->subsetsWithDup(subset);
    print(result);
}
