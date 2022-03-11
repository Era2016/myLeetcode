#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int> >);
class Solution {
public:
    /*
     * 不能掐住两端，用游标遍历中间数据
     * 会有数据遗漏
     * 不去重，可以？
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
        return vv;
    }

    vector<vector<int> > threeSum2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        vector<vector<int> > vv;

        for (int index = 0; index < length - 2; index ++) {
            if (nums[index] > 0) break;
            int start = index + 1, end = length - 1;
            while (start < end) {
                if (nums[start] + nums[end] == 0) {
                    vector<int> v = {nums[index], nums[start], nums[end]};
                    vv.push_back(v);
                } else if (nums[start] + nums[end] > 0) {
                    end --;
                    while (start < end && nums[end] == nums[end+1]) end --;
                } else {
                    start ++;
                    while (start < end && nums[start] == nums[start-1]) start ++;
                }
            }
        }
        return vv;
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
    vector<int> v = {-1,0,1,2,-1,-4}; // [-1,0,1][-1,-1,2]
    //vector<int> v = {}; // [] 
    //vector<int> v = {0,0,0,0}; // [0,0,0]
    vector<vector<int> > vv;
    
    Solution* so = new Solution();
    vv = so->threeSum2(v);
    print(vv);
}
