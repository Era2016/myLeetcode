#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int> >);
class Solution {
public:
    /*
     * 不能掐住两端，用游标遍历中间数据
     * 会有数据遗漏
     * 不去重，不可以
     * 见 目录下 test.cpp
     */
    /*vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        vector<vector<int> > vv;
        while (start < end) {
            // {-4,-1,-1,0,1,2}
            int tmpSum = nums[start] + nums[end];
            for (int index = start + 1; index < end; index ++) {
                if (nums[index] + tmpSum > 0) {
                    end --; 
                    while (start < end && nums[end] == nums[end+1]) { cout << end << endl; end --; }
                    break;
                } else if (nums[index] + tmpSum == 0) {
                    vector<int> v = {nums[start], nums[index], nums[end]}; 
                    vv.push_back(v);     
                } 

            }
            start ++;
            while (start < end && nums[start] == nums[start-1]) { cout << start << endl; start ++; }
        } 
        // [-1,-1,2] 丢失[-1,-1,0]

        map<vector<int>, int> m;
        for (int i = 0; i < vv.size(); i ++) {
            m.insert(pair<vector<int>, int>(vv[i], 1));
        }

        vector<vector<int> > ret;
        for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); it ++) {
            ret.push_back(it->first);
        }

        return ret;
    }*/

    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        vector<vector<int> > vv;

        // if (length > 2 && nums[0] == nums[length-1] && nums[0] == 0) return {{0, 0, 0}};
        // {-4,-1,-1,0,1,2} {-1,-1,0,1}
        for (int index = 0; index < length - 2; index ++) {
            if (nums[index] > 0) break;
            if (index >= 1 && nums[index-1] == nums[index]) continue; 
            int start = index + 1, end = length - 1;
            while (start < end) {
                if (nums[start] + nums[end] == -nums[index]) {
                    vector<int> v = {nums[index], nums[start], nums[end]};
                    //cout << nums[index] << "\t" << nums[start] << "\t" << nums[end] << endl;
                    vv.push_back(v);
                    start ++; while (start < end && nums[start] == nums[start-1]) start ++;
                    end --; while (start < end && nums[end] == nums[end+1]) end --;
                } else if (nums[start] + nums[end] > -nums[index]) {
                    end --;
                } else {
                    start ++;
                }
            }
        }
        return vv;
    }

	vector<vector<int>> threeSum_v2(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		// 枚举 a
		for (int first = 0; first < n; ++first) {
			// 需要和上一次枚举的数不相同
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			// c 对应的指针初始指向数组的最右端
			int third = n - 1;
			int target = -nums[first];
			// 枚举 b
			for (int second = first + 1; second < n; ++second) {
				// 需要和上一次枚举的数不相同
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				// 需要保证 b 的指针在 c 的指针的左侧
				while (second < third && nums[second] + nums[third] > target) {
					--third;
				}
				// 如果指针重合，随着 b 后续的增加
				// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
				if (second == third) {
					break;
				}
				if (nums[second] + nums[third] == target) {
					ans.push_back({nums[first], nums[second], nums[third]});
				}
			}
		}
		return ans;
	}
};

void print(vector<vector<int> > vv) {
	for (vector<vector<int> >::iterator it = vv.begin(); it != vv.end(); it ++ ) {
		for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i ++) {
			cout << *i << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	//vector<int> v = {-1,0,1,2,-1,-4}; // [-1,0,1][-1,-1,2]
	//vector<int> v = {}; // [] 
	vector<int> v = {0,0,0,0}; // [0,0,0]
	//vector<int> v = {1,-1,-1,0}; // [1,-1,0]
	vector<vector<int> > vv;

	Solution* so = new Solution();
	vv = so->threeSum(v);
	print(vv);
}
