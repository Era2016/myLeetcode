#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    vector<vector<string>> res;
    bool isPalindrome(string s, int start, int end) {
        for (int i=start, j=end; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

    void backtrack(vector<string>& strs, string s, int idx) {
        if (idx == s.length()) {
            res.push_back(strs);
            return;
        }

        for (int i = idx; i < s.length(); i ++) {
            if (!isPalindrome(s, idx, i)) {
                continue;
            }
            strs.push_back(s.substr(idx, i-idx+1));
            backtrack(strs, s, i+1);
            strs.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string> strs;
        backtrack(strs, s, 0);
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<string>> res;
    string s;
    
    auto print=[](vector<vector<string>>& res) {
        for (const auto& arr: res) {
            for (const auto& val: arr) {
                std::cout << val << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    };

    s = "aab";
    res = so->partition(s);
    print(res);
}
