#include <cstdlib>
#include <iostream>
#include <tuple>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    bool backtrack(string s, int idx, int& cnt) {
        if (idx == s.length()) {
            cnt ++;
            return true;
        }

        if (s[idx] >= '1' && s[idx] <= '9') {
            if (false == backtrack(s, idx+1, cnt)) return false;
        }

        string sNum = s.substr(idx, 2);
        if (sNum.length() == 2 && sNum >= "10" && sNum <= "26") {
           if (false == backtrack(s, idx+2, cnt)) return false;
        }
        return true;
    }
public:
    int numDecodings(string s) {
        int i = 0;
        while (i < s.length() && s[i] == '0') {
            i ++;
        }
        if (i == s.length()) return 0;
        if (i != 0) s.substr(i, -1);

        int cnt = 0;
        backtrack(s, 0, cnt);
        return cnt;
    }
};

int main() {
    Solution *so = new Solution();
    string s;

    s = "12";
    std::cout << so->numDecodings(s) << std::endl;

    s = "226";
    std::cout << so->numDecodings(s) << std::endl;

    s = "06";
    std::cout << so->numDecodings(s) << std::endl;

    s = "11106";
    std::cout << so->numDecodings(s) << std::endl;

    s = "00000";
    std::cout << so->numDecodings(s) << std::endl;

    s = "111111111111111111111111111111111111111111111";
    std::cout << so->numDecodings(s) << std::endl; // timeout
}
