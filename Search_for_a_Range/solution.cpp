#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>);
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        int mid, left = 0, right = length - 1; 
        bool find = false;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target < nums[mid]) {
                right = mid - 1; 
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                find = true;
                break;
            }
        }

        if (!find) return {-1, -1};

        int min = mid, max = mid;
        while (min > 0 && nums[min-1] == target) 
            min --;
        while (max < length-1 && nums[max+1] == target)
            max ++;

        return {min, max};
    }
};

void print(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++)
        cout << *it << "\t";
    cout << endl;
}

int main() {
    vector<int> v = {5,7,7,8,8,10};
    //vector<int> v = {5,7,7,8,8,10};
    //vector<int> v = {};
    int target = 8;
   
    Solution* so = new Solution();
    vector<int> ret = so->searchRange(v, target);
    print(ret);
}
