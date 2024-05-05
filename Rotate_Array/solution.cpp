#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    void rorate(vector<int>& nums, int k) {
        k = k%nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    auto print=[&]() {
        for (auto num: nums) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    };

    nums = {1,2,3,4,5,6,7};
    so->rorate(nums, 3);
    print();

    nums = {-1,-100,3,99};
    so->rorate(nums, 2);
    print();

    nums = {1};
    so->rorate(nums, 0);
    print();
}
