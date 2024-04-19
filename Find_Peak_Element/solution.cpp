#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    // 寻找最大值
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (right-left)/2 + left;
            if (nums[mid] < nums[mid+1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {1,2,3,1};
    std::cout << so->findPeakElement(nums) << std::endl;

    nums = {1,2,1,3,5,6,4};
    std::cout << so->findPeakElement(nums) << std::endl;

    nums = {1};
    std::cout << so->findPeakElement(nums) << std::endl;
}
