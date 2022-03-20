#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

};

void print(vector<vector<int>> vv) {
    for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
        for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void print(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++ it)
        cout << *it << "\t";
    cout << endl;
}

int main() {
    Solution* so = new Solution();
    vector<vector<int>> vv;

    //vector<int> v = {2,3,6,7};
    //int target = 7;

    vector<int> v = {2,3,5};
    int target = 8;

    //vector<int> v = {2};
    //int target = 1;
    vv = so->combinationSum(v, target);
    print(vv);
}
