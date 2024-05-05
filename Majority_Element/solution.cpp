#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0, cnt = 0;
        for (auto num: nums) {
            if (cnt == 0) x = num;
            
            cnt += (x==num) ? 1: -1;
        }
        return x;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {3,2,3};
    std::cout << so->majorityElement(nums) << std::endl;

    nums = {2,2,1,1,1,2,2};
    std::cout << so->majorityElement(nums) << std::endl;
}
