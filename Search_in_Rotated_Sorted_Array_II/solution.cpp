#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (right-left)/2 + left;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[left]) {
                left ++;
                continue;
            }
            // 前半部分有序
            if (nums[mid] > nums[left]) {
                if (target < nums[mid] && target >= nums[left]) { // 位于前半部分
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }  
            } else { // 后半部分有序
                if (target <= nums[right] && target > nums[mid]) { // 位于后半部分
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {2,5,6,0,0,1,2};
    cout << so->search(nums, 0) << endl;
    cout << so->search(nums, 3) << endl;
}
