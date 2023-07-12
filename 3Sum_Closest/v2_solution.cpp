#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v);
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        //print(nums);
        int minimum = INT_MAX;
        int result = 0;
        for (int i = 0; i < nums.size()-2; i ++) {
            int start = i + 1;
            int end = nums.size()-1;
            while (start < end) {
                int sum = nums[i]+nums[start]+nums[end];
                if (abs(target-sum) < minimum) {
                    minimum = abs(target-sum);
                    result = sum;
                }
                if (target > sum) {
                    start ++;
                } else if (target < sum) {
                    end --;
                } else {
                    break;
                }
            }
        }
        return result;
    }
};

void print(vector<int>& v) {
    for (const auto& i: v) {
        cout << i << "\t";
    }
    cout << endl;
}

int main() {
    Solution *so = new Solution();
    vector<int> v;

    v = {4,0,5,-5,3,3,0,-4,-5};// -> -2
    cout << so->threeSumClosest(v, -2) << endl;
}
