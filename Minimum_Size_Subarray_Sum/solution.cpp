#include <iostream>
#include <vector>

using std::vector;
using std::min;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int size = nums.size();
        int minLength = INT_MAX;
        int currSum = 0;
        while (right < size) {
            while (right < size && currSum < target) {
                currSum += nums[right ++];
            }
            
            while (left <= right && currSum >= target) {
                minLength = min(minLength, right-left);
                currSum -= nums[left ++];
            }
        }

        return (minLength==INT_MAX)? 0: minLength;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {2,3,1,2,4,3};
    std::cout << so->minSubArrayLen(7, nums) << std::endl;

    nums = {1,4,4}; 
    std::cout << so->minSubArrayLen(4, nums) << std::endl;

    nums = {1,1,1,1,1,1,1,1}; 
    std::cout << so->minSubArrayLen(11, nums) << std::endl;

    nums = {2,3,1,1,1,1,1};
    std::cout << so->minSubArrayLen(5, nums) << std::endl;
}
