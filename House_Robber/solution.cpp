#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )
	// dp[i] = max(dp[i-2] + nums[i], dp[i-1])
    int rob(vector<int>& nums) {
    	if (nums.size() == 0) {
			return 0;
		}

		vector<int> v(nums.size()+1, 0);
		v[1] = nums[0];
		for (int i = 2; i <= (int)nums.size(); i ++) {
			v[i] = max(v[i-2]+nums[i-1], v[i-1]);
		}

		return v[nums.size()];
    }
};

int main() {
	Solution* so = new Solution();
	vector<int> v = {1,2,3,1};
	int val = so->rob(v);
	cout << val << endl;

	v = {2,7,9,3,1};
	val = so->rob(v);
	cout << val << endl;

	v = {2,1,1,2};
	val = so->rob(v);
	cout << val << endl;

	v = {5,8,9,1,1,4}; 
	val = so->rob(v);
	cout << val << endl;
}
