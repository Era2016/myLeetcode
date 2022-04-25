#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> vv;
        vector<int> v;
        dfs(nums, vv, v, 0);
        return vv;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& vv, vector<int>& v, int idx) {
        vv.push_back(v);
        for (int i = idx; i < nums.size(); i ++) {
            if (i > idx && nums[i] == nums[i-1]) continue;
            //cout << "input stack: " << nums[i] << " index: "<< i << endl;
            v.push_back(nums[i]);
            dfs(nums, vv, v, i+1);
            //cout << "output stack: " << v.back() << endl;
            v.pop_back();
        }
    }
};

void print(vector<vector<int>>& vv) {
    for (vector<vector<int>>::iterator iter = vv.begin(); iter != vv.end(); iter ++) {
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it ++) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution* so = new Solution();
    vector<int> nums = {1,2,2};

    vector<vector<int>> vv = so->subsetsWithDup(nums); 
    print(vv);
}
