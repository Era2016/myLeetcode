#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int minLength = INT_MAX;
        vector<int> prefixSum(size+1, 0);
        
        for (int i = 1; i <= size; i ++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        for (int i = 1; i <= size; i ++) {
            int left = target + prefixSum[i-1];
            auto index = std::lower_bound(prefixSum.begin(), prefixSum.end(), left);
            if (index == prefixSum.end()) {
                continue;
            }
            
            int diff = index-prefixSum.begin();
            minLength = std::min(minLength, diff-i+1);
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
