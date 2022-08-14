#include <iostream>
#include <string>
#include <cassert>
#include <utility>

using std::string;
using std::pair;

class Solution {
private:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main () {
    Solution *so = new Solution();
    string origin, str;

    origin = "ababd";
    str = so->longestPalindrome(origin);
    std::cout << str << std::endl;
    //assert(so->longestPalindrome(origin) == "aba");

    origin = "cbbd";
    str = so->longestPalindrome(origin);
    std::cout << str << std::endl;
    
    
    origin = "a";
    str = so->longestPalindrome(origin);
    std::cout << str << std::endl;
}
