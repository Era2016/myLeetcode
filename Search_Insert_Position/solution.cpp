#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (high-low)/2 + low;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return low;
    }   
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {1,3,5,6};
    std::cout << so->searchInsert(nums, 5) << std::endl;

    nums = {1,3,5,6};
    std::cout << so->searchInsert(nums, 2) << std::endl;

    nums = {1,3,5,6};
    std::cout << so->searchInsert(nums, 7) << std::endl;
}
