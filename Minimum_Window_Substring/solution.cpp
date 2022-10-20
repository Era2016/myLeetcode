#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (auto v: t) need[v]++;

        int valid = 0;
        int left = 0, right = 0;
        int len = INT_MAX, start = 0;
        while (right < s.size()) {
            // c 是将移入窗口的字符
            char c = s[right];
            // 增大窗口
            right ++;

            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c] ++;
                if (window[c] == need[c])
                    valid ++;
            }

            /*** debug 输出的位置 ***/
            //printf("window: [%d, %d)\n", left, right);

            // 判断左侧窗口是否要收缩
            while (valid == need.size()) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }

                // c 是将移出窗口的字符
                char c = s[left];
                // 缩小窗口
                left ++;
                // 进行窗口内数据的一系列更新
                if (need.count(c)) {
                    if (need[c] == window[c]) 
                        valid --;
                    window[c] --;
                }
            }
        } // end of while
        return len == INT_MAX? "": s.substr(start, len);
    }
};

int main() {
    Solution *so = new Solution();
    string res = so->minWindow("ADOBECODEBANC", "ABC");    
    std::cout << res << std::endl;

    res = so->minWindow("a", "a");
    std::cout << res << std::endl;

    res = so->minWindow("a", "aa");
    std::cout << res << std::endl;
}
