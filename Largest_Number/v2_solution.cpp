#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::to_string;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp=[](int a, int b) {
            string s1 = to_string(a)+to_string(b);
            string s2 = to_string(b)+to_string(a);
            return s1 > s2;
        };
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";

        string str;
        for (auto& num: nums) {
            str += to_string(num);
        }
        return str;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;

    nums = {10,2};
    std::cout << so->largestNumber(nums) << std::endl;

    nums = {3,30,34,5,9};
    std::cout << so->largestNumber(nums) << std::endl;

    nums = {34323,3432};
    std::cout << so->largestNumber(nums) << std::endl;

    nums = {0,0};
    std::cout << so->largestNumber(nums) << std::endl;
}
