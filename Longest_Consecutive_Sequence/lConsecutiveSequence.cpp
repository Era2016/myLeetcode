#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <iterator>
#include <algorithm>

using namespace std;

void print(vector<int> v);

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int numsLength = (int) nums.size();
		unordered_set<int> s;
		for (int i = 0; i < numsLength; i ++) {
			s.insert(nums[i]);
		}

		int maxLength = 0;

		// 迭代器遍历
        unordered_set<int>::iterator iter = s.begin();
        while (iter != s.end()) {
        	if (s.find(*iter-1) == s.end()) { // ser中不存在
        		int currNum = *iter;
        		int currLength = 1;

        		while (s.find(currNum+1) != s.end()) {
        			currNum ++;
        			currLength ++;
        		}

        		maxLength = max(maxLength, currLength);
        	}
        	iter ++;
        }

        // 数组遍历
        /*for (int i = 0; i < numsLength; i ++) {
        	if (s.find(nums[i]-1) == s.end()) {
        		int currNum = nums[i];
        		int currLength = 1;
        		while (s.find(currNum+1) != s.end()) {
        			currNum ++;
        			currLength ++;
        		}

        		maxLength = max(maxLength, currLength);
        	}
        }*/
        return maxLength;
	}

	int longestConsecutive2(vector<int>& nums) {
		int numsLength = (int) nums.size();
		if (numsLength == 0) {
			return 0;
		}

		sort(nums.begin(), nums.end());

		int maxLength = 0;
		int currLength = 1;
		for (int i = 1; i < numsLength; i ++) {
			if (nums[i] == nums[i-1] + 1) {
				currLength ++;
			} else if (nums[i] == nums[i-1]) {
				// do nothing
			} else {
				maxLength = max(maxLength, currLength);
				currLength = 1;
			}
		}

		maxLength = max(maxLength, currLength);
		return maxLength;
	}

	// 参数中包含最大值/最小值时，vector<int> 会溢出
    int longestConsecutive3(vector<int>& nums) {
    	int numsLength = (int) nums.size();
    	if (numsLength == 0) {
    		return 0;
    	}

    	int maxNum = nums[0];
    	int minNum = nums[0];
    	for (int i = 1; i < numsLength; i ++) {
    		maxNum = max(maxNum, nums[i]);
    		minNum = min(minNum, nums[i]);
    	}

    	//cout << "min: " << minNum << " max: " << maxNum << endl;

    	// TODO 有重复的数字，需要解决
        vector<int> v(maxNum-minNum+1, 0);
        for (int i = 0; i < numsLength; i ++) {
        	v[nums[i] - minNum] = nums[i] - minNum;
        }

        //cout << "vector max size: " << v.size() << endl;
        //print(v);

        int maxLength = 1;
        int curLength = 1;
        for (int i = 1; i < (int) v.size(); i ++) {
        	if (v[i] - v[i-1] == 1) {
        		curLength ++;
        	} else {
        		maxLength = max(maxLength, curLength);
        		curLength = 1;
        	}
        }
        maxLength = max(maxLength, curLength);

        return maxLength;
    }
};

void print(vector<int> v) {
	for (int i = 0; i < (int) v.size(); i ++) {
		cout << v[i] << "\t";
	}
	cout << endl;
}

int main() {
	// vector<int> nums1 = {10, 4, 20, 1, 3, 2};
	// vector<int> nums2 = {1};
	// vector<int> nums3 = {0};
	// vector<int> nums4 = {};
	// vector<int> nums5 = {-1,0};
	// vector<int> nums6 = {-1,-4,-2,-3,0,1,3};
	// vector<int> nums7 = {9,1,4,7,3,-1,0,5,8,-1,6};
	// vector<int> nums8 = {1,2,0,1};

	Solution* so = new Solution();
	vector<vector<int> > vv = {
		{10, 4, 20, 1, 3, 2},
		{1},
		{0},
		{},
		{-1,0},
		{-1,-4,-2,-3,0,1,3},
		{9,1,4,7,3,-1,0,5,8,-1,6},
		{1,2,0,1}
	};
	for (int i = 0; i < (int) vv.size(); i ++) {
		cout << "=======start======" << endl;
		print(vv[i]);
		//cout << so->longestConsecutive(vv[i]) << endl;
		cout << so->longestConsecutive2(vv[i]) << endl;
		cout << "=======end========" << endl;
	}
	
	
}

