#include <iostream>
#include <unordered_map>

using std::string;
using std::unordered_map;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, need;
        for (const auto& c: t) need[c] ++;

        int left = 0, right = 0;
        int valid = 0;
        int minLength = INT_MAX; 
        int start = 0;
        while (right < s.length()) {
            char c = s[right ++];
            if (need.count(c)) {
                window[c] ++;
                if (window[c] == need[c]) {
                    valid ++;
                }
            }

            while (left < right && valid == need.size()) {
                if (minLength > right-left) {
                    minLength = right - left;
                    start = left;
                }

                char d = s[left ++];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid --;
                    }
                    window[d] --;;
                }
            }
        }
        return (minLength == INT_MAX)? "": s.substr(start, minLength);
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->minWindow("ADOBECODEBANC", "ABC") << std::endl;
    std::cout << so->minWindow("a", "a") << std::endl;
    std::cout << so->minWindow("a", "aa") << std::endl;
    std::cout << so->minWindow("cabwefgewcwaefgcf", "cae") << std::endl;
}
