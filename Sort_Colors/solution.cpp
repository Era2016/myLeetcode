#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cursor = 0;
        int left = 0, right = n-1;
        while (cursor < n) {
            if (nums[cursor] == 0) {
                int i = left;
                while (i<cursor && nums[i]==0) {
                    i ++;
                }
                if (i < cursor) {
                    std::swap(nums[cursor], nums[i]);
                    left = i;
                } else {
                    left = i;
                    cursor ++;
                }
            } else if (nums[cursor] == 1) {
                cursor ++;
            } else {
                int i = right;
                while (i>cursor && nums[i]==2) {
                    i --;
                }
                if (i > cursor) {
                    std::swap(nums[cursor], nums[i]);
                    right = i;
                } else {
                    break;
                }
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

    nums = {0,0,2,1};
    so->sortColors(nums);
    print();
}
