#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    const int segCnt = 4;
    vector<string> res;
    vector<int> intermediate;
    void dfs(string s, int segId, int idx) {
        if (segId == segCnt) {
            if (idx == s.length()) {
                string str;
                for (auto n: intermediate) {
                    str += std::to_string(n)+'.';
                } 
                str.pop_back();
                res.push_back(str);
            }
            return;
        }
        if (idx == s.length()) {
            return;
        }

        if (s[idx] == '0') {
            intermediate[segId] = 0;
            dfs(s, segId+1, idx+1);
        }

        int addr = 0;
        for (int i = idx; i < s.length(); i ++) {
            addr = 10*addr + (s[i]-'0');
            if (addr > 0 && addr <= 255) {
                intermediate[segId] = addr;
                dfs(s, segId+1, i+1);
            } else {
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        this->res.clear();
        this->intermediate.clear();
        this->intermediate.resize(this->segCnt);
        dfs(s, 0, 0);
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
    
    s = "0000";
    res = so->restoreIpAddresses(s);
    print();

    s = "101023";
    res = so->restoreIpAddresses(s);
    print();
}
