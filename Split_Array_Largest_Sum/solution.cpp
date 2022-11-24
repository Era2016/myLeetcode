#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;
using std::max;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for (auto k: nums) {
            left = max(left, k);
            right += k;
        }

        while (left <= right) {
            int mid = left + (right - left)/2;
            if (_split(nums, mid) <= k) { // _split(nums, mid) left_bound
                right = mid - 1;
            } else {
                left = mid + 1;
            } 
        }
        return left;
    }

    // sum, 每次分割的最大和
    // 返回值，分割次数
    int _split(vector<int>& nums, int sum) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ) {
            int curSum = 0;
            while (i < nums.size()) {
                if (curSum + nums[i] <= sum) {
                    curSum += nums[i ++];
                } else {
                    break;
                }
            }
            cnt ++;
        } 
        return cnt;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    int ret, k;

    v = {7,2,5,10,8};
    k = 2; 
    ret = so->splitArray(v, k);
    //cout << ret << endl;
    assert(ret == 18);
   
    v = {1,2,3,4,5};
    k = 2; 
    ret = so->splitArray(v, k);
    assert(ret == 9);
   
    v = {1,4,4};
    k = 3; 
    ret = so->splitArray(v, k);
    assert(ret == 4);
}
