#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int siz = nums.size();
        vector<int> dp_max(siz+1, 0); 
        vector<int> dp_min(siz+1, 0); 
        dp_max[0] = 1;
        dp_min[0] = 1;

        for (int i = 1; i <= siz; i ++) {
            dp_max[i] = std::max(std::max(dp_max[i-1]*nums[i-1], dp_min[i-1]*nums[i-1]), nums[i-1]);
            dp_min[i] = std::min(std::min(dp_max[i-1]*nums[i-1], dp_min[i-1]*nums[i-1]), nums[i-1]);
        }

        return *max_element(dp_max.begin()+1, dp_max.end());
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {2,3,-2,4};
    std::cout << so->maxProduct(nums) << std::endl;

    nums = {-2,0,-1};
    std::cout << so->maxProduct(nums) << std::endl;
}
