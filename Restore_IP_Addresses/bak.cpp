#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Solution {
private:
    vector<string> res;
    void backtrack(string s, string& interS, int idx) {
        if (idx == s.length()) {
            interS.pop_back();
            res.push_back(interS);
            return;
        }

        for (int i = 1; i <= 3; i ++) {
            string str = s.substr(idx, i);
            if (i == 2 && str[0] == '0') {
                continue;
            }
            if (i == 3) {
                if (str[0] == '0' || str[0] >= '3') continue;
                if (str[0] == '2' && (str[1] > '5' || str[2] > '5')) continue;
            }
            int cnt = 0, cursor = 0;
            bool overFlow = false;
            while (cursor < str.length()) {
                int newCursor = str.find('.', cursor);
                if (newCursor != -1) cnt ++;
                if (cnt >= 4) { overFlow = true; break; } 
                cursor = newCursor+1;
            }

            if (overFlow) continue;
            interS += str + '.';
            backtrack(s, interS, idx+i);
            interS = s.substr(0, s.length()-i-1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string interS;
        backtrack(s, interS, 0);
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> res;
    string s;
    auto print=[&]() {
        for (auto s: res) {
            std::cout << s << " ";
        }
        std::cout << "\n";
    };

    s = "25525511135";
    res = so->restoreIpAddresses(s);
    print();
}
