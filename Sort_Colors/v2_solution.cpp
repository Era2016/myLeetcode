#include <array>
#include <iostream>
#include <optional>
#include <vector>

using std::vector;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size()-1;
        for (int i = 0; i <= p2; i ++) {
            while (i <= p2 && nums[i] == 2) {
                std::swap(nums[i], nums[p2]);
                p2 --;
            }

            if (nums[i] == 0) {
                std::swap(nums[i], nums[p0]);
                p0 ++;
            }
        }
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    auto print=[&]() {
        for (const auto& n: nums) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    };

    nums = {2,0,2,1,1,0};
    so->sortColors(nums);
    print();

    nums = {2,0,1};
    so->sortColors(nums);
    print();

    nums = {0,2,0,1,2};
    so->sortColors(nums);
    print();
}
