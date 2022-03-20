#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v);
void print(vector<vector<int>> vv);
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

void print(vector<vector<int> > vv) {
	for (int i = 0; i < (int)vv.size(); i ++) {
		for (int j = 0; j < (int) vv[0].size(); j ++) {
			cout << vv[i][j] << "\t";
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
	vector<int> nums = {1,2,3};
	Solution* so = new Solution();
	vv = so->permute(nums);
	print(vv);
}
