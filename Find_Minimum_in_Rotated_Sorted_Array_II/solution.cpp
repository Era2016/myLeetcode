#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int ansmin = INT_MAX;
        while (left <= right) {
            int mid = (right-left)/2 + left;
            if (nums[mid] < nums[right]) {
                ansmin = std::min(ansmin, nums[mid]);
                right = mid - 1;
            } else if (nums[mid] > nums[right]) {
                ansmin = std::min(ansmin, nums[right]);
                left = mid + 1;
            } else {
                ansmin = std::min(ansmin, nums[mid]);
                right --; 
            }
        }
        return ansmin;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {1,3,5};
    std::cout << so->findMin(nums) << std::endl; // 1

    nums = {2,2,2,0,1};
    std::cout << so->findMin(nums) << std::endl; // 0

    nums = {1,3,3};
    std::cout << so->findMin(nums) << std::endl; // 1
}
