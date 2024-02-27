#include <cmath>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0, maxPosition = 0;
        int step = 0;
        for (int i = 0; i < nums.size()-1; i ++) {
            maxPosition = std::max(maxPosition, nums[i]+i);
            if (end == i) {
                end = maxPosition;
                step ++;
            }
        }
        return step;
    }

    int jump_v2(vector<int>& nums) {
        int start = 0, end = 1;
        int step = 0;
        while (end < nums.size()) {
            int maxPosition = 0;
            for (int i = start; i < end; i ++) {
                maxPosition = std::max(maxPosition, nums[i]+i);
            }
            start = end;
            end = maxPosition+1;
            step ++;
        }
        return step;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {2,3,1,1,4};
    std::cout << so->jump(nums) << std::endl;
    std::cout << so->jump_v2(nums) << std::endl;

    nums = {2,3,0,1,4};
    std::cout << so->jump(nums) << std::endl;
    std::cout << so->jump_v2(nums) << std::endl;
}
