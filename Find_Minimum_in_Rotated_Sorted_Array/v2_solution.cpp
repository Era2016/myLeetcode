#include <iostream>
#include <vector>

using std::vector;
using std::min;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ansmin = INT_MAX;
        int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] < nums[r]) { // sorted 
                ansmin = min(ansmin, nums[mid]);
                r = mid - 1;
            }
            else {
                ansmin = min(ansmin, nums[r]);
                l = mid + 1;
            }
        }
        return ansmin;
    }
};


int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {3,4,5,1,2};
    std::cout << so->findMin(nums) << std::endl; // 1

    nums = {4,5,6,7,0,1,2};
    std::cout << so->findMin(nums) << std::endl; // 0

    nums = {11,13,15,17};
    std::cout << so->findMin(nums) << std::endl; // 11

    nums = {1};
    std::cout << so->findMin(nums) << std::endl; // 1

    nums = {1,2};
    std::cout << so->findMin(nums) << std::endl; // 1
}
