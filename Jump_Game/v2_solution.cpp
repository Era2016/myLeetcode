#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPosition = 0;
        int length = nums.size();
        for (int i = 0; i < length; i ++) {
            if (i <= maxPosition) {
                maxPosition = std::max(maxPosition, i+nums[i]);
                if (maxPosition >= length-1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {2,3,1,1,4};
    assert(true == so->canJump(nums));

    nums = {3,2,1,0,4};
    assert(false == so->canJump(nums));

    nums = {0};
    assert(true == so->canJump(nums));
}
