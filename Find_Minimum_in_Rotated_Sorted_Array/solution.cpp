#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (right-left)/2 + left;
            if (nums[mid] < nums[right]) { // 5,1,2,3,4 
                right = mid;
            } else { // 3,4,5,1,2 
                left = mid + 1;
            }
        }

        return nums[left];
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
