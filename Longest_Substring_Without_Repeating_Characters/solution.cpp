#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;

        int left = 0, right = 0;
        int maxLength = 0;
        while (right < s.size()) {
            char c = s[right ++];
            window[c] ++;
            
            while (window[c] > 1) {
                char d = s[left ++];
                window[d] --;
            }
            
            maxLength = right-left > maxLength? right-left: maxLength;
        }
        return maxLength;
    }
};

int main() {
    Solution *so = new Solution();
    int len = so->lengthOfLongestSubstring("abcabcbb");
    std::cout << sizeof("abcabcbb") << ":"<< len << std::endl;

    len = so->lengthOfLongestSubstring("bbbbb");
    std::cout << sizeof("bbbbb") << ":" << len << std::endl;

    len = so->lengthOfLongestSubstring("pwwkew");
    std::cout << len << std::endl;
}
