#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int index = len-1;
        while (index > 0 && nums[index] <= nums[index-1]) {
            index --;
        }
        if (index == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        for (int i = len-1; i >= 0; i --) {
            if (nums[i] > nums[index-1]) {
                std::swap(nums[i], nums[index-1]);
                sort(nums.begin()+index, nums.end());
                return;
            }
        }
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    auto print=[](vector<int>& nums) {
        for (const auto& n: nums) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    };

    nums = {1,2,3,4,5};
    for (int i = 0; i < 120; i ++) {
        so->nextPermutation(nums);
        print(nums);
    } 

    nums = {1,1,5};
    for (int i = 0; i < 6; i ++) {
        so->nextPermutation(nums);
        print(nums);
    }
}
