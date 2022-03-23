#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> v;
        vector<vector<int>> vv;
        vector<int> used(nums.size(), 0);
        dfs(nums, vv, v, target, used, 0);
        return vv;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& vv, vector<int>& v, int target, vector<int>& used, int idx) {
        if (target < 0) {
            return; 
        } else if (target == 0) {
            vv.push_back(v);
            return;
        } else {
            for (int i = idx; i < nums.size(); i ++) {
                if (!used[i]) {
                    used[i] = 1;
                    v.push_back(nums[i]);
                    dfs(nums, vv, v, target-nums[i], used, idx+1);
                    used[i] = 0;
                    v.pop_back();
                }
            }}
    }
};
