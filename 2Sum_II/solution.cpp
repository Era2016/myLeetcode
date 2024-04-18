#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::unordered_set;
class Solution {
public:
    vector<vector<int>> func(vector<int>& nums, int target) {
        unordered_set<int> us(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (auto num: nums) {
            if (us.find(target-num) != us.end()) {
                res.push_back({num, target-num});
                us.erase(num);
                us.erase(target-num);
            }
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    vector<vector<int>> res;
    auto print=[&]() {
        for (auto arr: res) {
            for (auto v: arr) {
                std::cout << v << " ";
            }
            std::cout << "\n";
        }
    };

    nums = {1,5,2,3,10,4,6,1,5,2,3,10,4,6};
    res = so->func(nums, 6);
    print();
}
