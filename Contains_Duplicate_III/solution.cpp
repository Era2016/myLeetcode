#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::max;
using std::min;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long> window; // int 可能会导致溢出
        int index = 0;
        while (index < nums.size()) {
            auto iter = window.lower_bound(nums[index]-valueDiff);
            if (iter != window.end() && *iter<=nums[index]+valueDiff) {
                return true;
            }

            window.insert(long(nums[index]));
            if (index >= indexDiff) {
                window.erase(nums[index-indexDiff]);
            }
            index ++;
        }
        return false;
    } 
    bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> rec;
        for (int i = 0; i < n; i++) {
            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            rec.insert(nums[i]);
            if (i >= k) {
                rec.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    
    nums = {1,2,3,1};
    std::cout << so->containsNearbyAlmostDuplicate(nums, 3, 0) << std::endl;

    nums = {1,5,9,1,5,9};
    std::cout << so->containsNearbyAlmostDuplicate(nums, 2, 3) << std::endl;

    nums = {1,2,2,3,4,5};
    std::cout << so->containsNearbyAlmostDuplicate(nums, 3, 0) << std::endl;
}
