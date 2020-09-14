#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
		vector<vector<int> > vv;
       	permutation(vv, nums, 0); 
		return vv;
    }

private:
	void permutation(vector<vector<int> >& vv, vector<int>& v, int begin) {
		if (begin == (int)v.size()) {
			vv.push_back(v);
			return;
		}	

		for (int i = begin; i < (int)v.size(); i ++) {
			swap(v[i], v[begin]);
			permutation(vv, v, begin+1);
			swap(v[i], v[begin]);
		}
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

int main() {
	vector<vector<int> > vv;
	vector<int> nums = {1,2,3};
	Solution* so = new Solution();
	vv = so->permute(nums);
	print(vv);
}
