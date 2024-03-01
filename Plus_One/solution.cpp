#include <algorithm>
#include <atomic>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int added = 0;
        vector<int> res;
        for (int i = len-1; i >= 0|| added; i --) {
            int auxNum = (i==len-1)? added+1: added;
            int digit = (i>=0)? digits[i]: 0; 

            int newDigit = auxNum + digit;
            res.push_back(newDigit%10);
            added = newDigit/10;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> digits, res;
    auto print=[&]() {
        for (const auto d: res) {
            std::cout << d << "";
        }
        std::cout << "\n";
    };

    digits = {1,2,3};
    res = so->plusOne(digits);
    print();

    digits = {4,3,2,1};
    res = so->plusOne(digits);
    print();

    digits = {0};
    res = so->plusOne(digits);
    print();
}
