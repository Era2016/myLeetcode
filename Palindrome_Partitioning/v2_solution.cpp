#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    vector<vector<string>> res;
    void backtrack(vector<vector<int>>& dp, vector<string>& strs, string s, int idx) {
        if (idx == s.length()) {
            res.push_back(strs);
            return;
        }

        for (int i = idx; i < s.length(); i ++) {
            if (s[i] == s[idx] && (i-idx <= 2||dp[idx+1][i-1])) {
                dp[i][idx] = true;
                strs.push_back(s.substr(idx, i-idx+1));
                backtrack(dp, strs, s, i+1);
                strs.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<string> interV;
        backtrack(dp, interV, s, 0);

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
