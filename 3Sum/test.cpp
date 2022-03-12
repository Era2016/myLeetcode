#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print(vector<vector<int> >);
class Solution {
public:
    /*
     * 不能掐住两端，用游标遍历中间数据
     * 会有数据遗漏
     * 不去重，可以？ 
     * Input [-2,0,1,1,2]
     * Output [[-2,0,2]]
     * Expected [[-2,0,2],[-2,1,1]]
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        vector<vector<int> > vv;
        while (start < end) {
            // {-4,-1,-1,0,1,2}
            int tmpSum = nums[start] + nums[end];
            for (int index = start + 1; index < end; index ++) {
                if (nums[index] + tmpSum > 0) {
                    end --; 
                    break;
                } else if (nums[index] + tmpSum == 0) {
                    vector<int> v = {nums[start], nums[index], nums[end]}; 
                    vv.push_back(v);     
                } 

            }
            start ++;
        } 
        // [-1,-1,2] 丢失[-1,-1,0]
         
        return filter(vv);
    }

    vector<vector<int> > filter(vector<vector<int> >& vv) {
        map<vector<int>, int> m;
        for (int i = 0; i < vv.size(); i ++) {
            m.insert(pair<vector<int>, int>(vv[i], 1));
        }

        vector<vector<int> > ret;
        for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); it ++) {
            ret.push_back(it->first);
        }

        return ret;
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

void print(map<vector<int>, int> m) {
    for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); it ++) {
        vector<int> v = it->first;
        for (int i = 0; i < v.size(); i ++) {
            cout << v[i] << "\t";
        }
        //for (vector<int>::iterator i = it->first.begin(); i != it->first.end(); i ++) {
        //    cout << *i << "\t";
        //}
        cout << endl;
    }
}

int main() {
	//vector<int> v = {-1,0,1,2,-1,-4}; // [-1,0,1][-1,-1,2]
	//vector<int> v = {}; // [] 
	//vector<int> v = {0,0,0,0}; // [0,0,0]
	//vector<int> v = {1,-1,-1,0}; // [1,-1,0]
    vector<int> v = {-2,0,1,1,2}; // wrong
	vector<vector<int> > vv;

	Solution* so = new Solution();
	vv = so->threeSum(v);
    print(vv);
}
