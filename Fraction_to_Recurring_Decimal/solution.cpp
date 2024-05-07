#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
class Solution {
public:
    // 分子/分母
    string fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = numerator;
        long denominatorLong = denominator;

        if (numeratorLong % denominatorLong == 0) {
            return std::to_string(numeratorLong/denominatorLong);
        }

        string ans;
        if (numeratorLong < 0 ^ denominatorLong < 0) {
            ans.push_back('-');
        }

        // 整数部分
        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        long integerPart = numeratorLong / denominatorLong;
        ans += std::to_string(integerPart);
        ans.push_back('.');

        // 小数部分
        string fractionPart;
        unordered_map<long, int> remainderIndexMap;
        long remainder = numeratorLong % denominatorLong;
        int index = 0;
        while (remainder != 0 && !remainderIndexMap.count(remainder)) {
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fractionPart += std::to_string(remainder / denominatorLong);
            remainder %= denominatorLong;
            index ++;
        }

        if (remainder != 0) {
            int insertIndex = remainderIndexMap[remainder];
            fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex);
            fractionPart.push_back(')');
        }
        ans += fractionPart;
        return ans;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->fractionToDecimal(1, 2) << std::endl;
    std::cout << so->fractionToDecimal(2, 1) << std::endl;
    std::cout << so->fractionToDecimal(4, 333) << std::endl;
}
