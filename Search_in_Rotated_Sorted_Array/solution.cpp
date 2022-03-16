#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        if (!length) return -1;

        int mid, left = 0, right = length - 1;
        if (left == right) return nums[0] == target ? left: -1;

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[right] >= nums[mid]) { // else {} 判断也可以
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }    
};

int main() {
    vector<int> v = {3,4,5,6,0,1,2};
    int target = 0;
    Solution* so = new Solution();
    cout << so->search(v, target) << endl;
}
