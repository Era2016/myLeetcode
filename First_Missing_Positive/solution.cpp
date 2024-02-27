#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            while (nums[i] != i+1) { 
                if (nums[i] <= 0 || nums[i] >= nums.size() || 
                        nums[i] == nums[nums[i]-1]) {
                    break;
                }
                std::swap(nums[i], nums[nums[i]-1]);
                //int idx = nums[i] - 1;
                //nums[i] = nums[idx];
                //nums[idx] = idx + 1;
            }
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {1,2,0};
    std::cout << so->firstMissingPositive(nums) << std::endl;

    nums = {3,4,-1,1};
    std::cout << so->firstMissingPositive(nums) << std::endl;

    nums = {7,8,9,11,12};
    std::cout << so->firstMissingPositive(nums) << std::endl;
}
