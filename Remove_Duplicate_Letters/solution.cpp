#include <iostream>
#include <unordered_map>
#include <deque>
#include <cassert>

using std::unordered_map;
using std::deque;
using std::string;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastIndex;
        unordered_map<char, int> visit;
        deque<char> dq;

        for (int i = 0; i < s.length(); i ++) {
            lastIndex[s[i]] = i;            
        }

        for (int i = 0; i < s.length(); i ++) {
            if (visit[s[i]]) continue;
            while (!dq.empty() && dq.back() > s[i] && i < lastIndex[dq.back()]) {
                visit[dq.back()] = 0;
                dq.pop_back();
            }
            dq.push_back(s[i]);
            visit[s[i]] = 1;
        }
        string ss;
        while (!dq.empty()) {
            ss += dq.front();
            dq.pop_front();
        }

        return ss;
    }
};

int main () {
    Solution *so = new Solution();
    string s, ret;
    
    s = "bcabc";
    ret = so->removeDuplicateLetters(s);
    std::cout << ret << std::endl;
    //assert(ret == "abc");

    s = "cbacdcbc";
    ret = so->removeDuplicateLetters(s);
    std::cout << ret << std::endl;
    //assert(ret == "acdb");
}
