#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> vv;
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(nums, vv, v, used, 0);
        return vv;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& vv, vector<int>& v, vector<int>& used, int depth) {
        if (depth == nums.size()) {
            vv.push_back(v);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (!used[i]) {
                // 数据有序,相同数字相邻
                // 选择从左往右第一个未被填过的数字
                if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                    continue;
                } else {
                    used[i] = 1;
                    v.push_back(nums[i]);
                    dfs(nums, vv, v, used, depth+1);
                    used[i] = 0;
                    v.pop_back();
                } 
            }
        }
    }
};

void print(vector<vector<int> > vv) {
    for (vector<vector<int>>::iterator itea = vv.begin(); itea != vv.end(); itea ++) {
        for (vector<int>::iterator it = (*itea).begin(); it != (*itea).end(); it ++) {
            cout << *it << "\t";
        }
        cout << endl;
    }
	cout << endl;
}

void print(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++) 
        cout << *it << "\t";
    cout << endl;
}

int main() {
	vector<vector<int> > vv;
	vector<int> nums = {1,2,1};
	//vector<int> nums = {1,2,3};
	//vector<int> nums = {1,1,2,2};
	Solution* so = new Solution();
	vv = so->permuteUnique(nums);
	print(vv);
}
