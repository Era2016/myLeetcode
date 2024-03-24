#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(32, 0);
        for (auto num: nums) {
            for (int i = 0; i < 32; i ++) {
                v[i] += num&1;
                num >>= 1;
            }
        }
        for (auto& count: v) {
            count %= 3;
        }

        int number = 0;
        for (int i = 0; i < 32; i ++) {
            number <<= 1;
            number |= v[31-i];
        }
        return number;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;

    v = {2,2,3,2};
    std::cout << so->singleNumber(v) << std::endl;

    v = {0,1,0,1,0,1,99};
    std::cout << so->singleNumber(v) << std::endl;
}
