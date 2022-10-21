#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (auto c :s1) need[c] ++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right ++];
            if (need.count(c)) {
                window[c] ++;
                if (need[c] == window[c]) valid ++;
            }

            while (right - left >= s1.size()) {
                if (valid == need.size()) {
                    return true;
                }
                char c = s2[left ++];
                if (need.count(c)) {
                    if (need[c] == window[c]) {
                        valid --;
                    }
                    window[c] --;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution *so = new Solution();
    bool res = so->checkInclusion("ab", "eidbaooo");
    std::cout << res << std::endl;
    
    res = so->checkInclusion("ab", "eidboaoo");
    std::cout << res << std::endl;
}
