#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vv;
        vector<int> v;

        dfs(nums, vv, v, 0);
        return vv;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& vv, vector<int>& v, int idx) {
        vv.push_back(v);

        for (int i = idx; i < nums.size(); i ++) {
            v.push_back(nums[i]);
            dfs(nums, vv, v, i+1);
            v.pop_back();
        }
    }
};

void print(vector<vector<int>> vv) {
    for (vector<vector<int>>::iterator iter = vv.begin(); iter != vv.end(); iter ++) {
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it ++) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<int> v = {1,2,3};
    Solution* so = new Solution();
    vector<vector<int>> vv = so->subsets(v);
    print(vv);
}
