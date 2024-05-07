#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
int singleNumber(vector<int>& nums) {
    vector<int> v(32);
    for (int i = 0; i < 32; i ++) {
        for (auto num: nums) {
            v[i] += num&1;
            num >>= 1;
        }
    }

    for (auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto &i: v) {
        i %= 3; 
    }
    return 1;
}
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {2,2,3,2};
    std::cout << so->singleNumber(nums) << std::endl;
}
