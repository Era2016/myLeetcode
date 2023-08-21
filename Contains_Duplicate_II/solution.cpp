#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::unordered_set;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> us;
        int index = 0;
        while (index < nums.size()) {
            if (index - k >= 1) {
                us.erase(nums[index-k-1]);
            }
            
            if (us.count(nums[index]) >= 1) {
                return true;
            }
            
            us.emplace(nums[index ++]);
        }

        return false;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {1,2,3,1};
    std::cout << so->containsNearbyDuplicate(nums, 3) << std::endl;

    nums = {1,0,1,1};
    std::cout << so->containsNearbyDuplicate(nums, 1) << std::endl;

    nums = {1,2,3,1,2,3};
    std::cout << so->containsNearbyDuplicate(nums, 2) << std::endl;
}
