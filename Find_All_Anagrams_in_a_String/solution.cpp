#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (auto c: p) need[c] ++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> v;
        while (right <= s.size()) {
            char c = s[right ++];
            if (need.count(c)) {
                window[c] ++;
                if (need[c] == window[c])
                    valid ++;
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    v.push_back(left);
                }

                char c = s[left ++];
                if (need.count(c)) {
                    if (need[c] == window[c])
                        valid --;
                    window[c] --;
                }
            }
        }
        return v;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;

    auto print = [](vector<int> v) { for (auto k: v) std::cout << k << std::endl; std::cout << std::endl; };
    v = so->findAnagrams("cbaebabacd", "abc");
    print(v);

    v = so->findAnagrams("abab", "ab");
    print(v);
}
