#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> um;
        int maxLength = 0;
        while (right < s.length()) {
            char c = s[right ++];
            um[c] ++;
            
            while (um[c] > 1 && left < right) {
                char d = s[left ++];
                um[d] --;
            }

            maxLength = (right-left > maxLength)? right-left: maxLength;
        }
        return maxLength;
    }
};

int main() {
    Solution *so = new Solution();
    string s;

    std::cout << so->lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << so->lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << so->lengthOfLongestSubstring("pwwkew") << std::endl;
}
