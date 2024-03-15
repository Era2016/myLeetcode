#include <iostream>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end()), us2;
        int maxVal = 0;
        for (const auto& num: nums) {
            if (us2.find(num) != us2.end()) {
                continue;
            }
            int cnt1 = 1;
            while (us.find(num+cnt1) != us.end()) {
                cnt1 ++;
                us2.insert(num+cnt1);
            } 

            int cnt2 = 1;
            while (us.find(num-cnt2) != us.end()) {
                cnt2 ++;
                us2.insert(num-cnt2);
            }
            maxVal = std::max(maxVal, cnt1+cnt2-1);
            
        }
        return maxVal;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {100,4,200,1,3,2};
    std::cout << so->longestConsecutive(nums) << std::endl; // 4

    nums = {0,3,7,2,5,8,4,6,0,1};
    std::cout << so->longestConsecutive(nums) << std::endl; // 9

    nums = {};
    std::cout << so->longestConsecutive(nums) << std::endl;
}
