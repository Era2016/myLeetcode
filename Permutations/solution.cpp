#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> vv;
        vector<int> used(nums.size(), 0);
        dfs(nums, v, vv, used, 0);
        return vv;
    }

    void dfs(vector<int>& nums, vector<int>& v, vector<vector<int>>& vv, vector<int>& used, int depth) {
        if (depth == nums.size()) {
            vv.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (!used[i]) {
                used[i] = true;
                v.push_back(nums[i]);
                dfs(nums, v, vv, used, depth + 1);
                used[i] = false;
                v.pop_back();
            }
        }
    }
};

void print(vector<vector<int>> vv) {
    for (vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); it ++) {
        for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i ++) {
            cout << *i << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    //vector<int> v = {1, 2, 3};
    //vector<int> v = {0, 1};
    vector<int> v = {1};

    vector<vector<int>> vv;
    Solution* so = new Solution();
    vv = so->permute(v);
    print(vv);
}
