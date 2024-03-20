#include <iostream>
#include <vector>
#include <assert.h>

using std::vector;
using std::string;
class Solution {
private:
    int minVal;
    void dfs(string s, vector<vector<int>>& dp, int idx, int cut) {
        if (idx == s.length()) {
            minVal = std::min(minVal, cut-1);
            return;
        }

        for (int i = idx; i < s.length(); i ++) {
            if (s[i] == s[idx] && (i-idx<=2 || dp[idx+1][i-1])) {
                dp[idx][i] = true;
                dfs(s, dp, i+1, cut+1);
            }
        }
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        this->minVal = n-1;
        dfs(s, dp, 0, 0);
        return this->minVal;
    }
};

int main() {
    Solution *so = new Solution();
    string s;

    s = "aab";
    assert(so->minCut(s) == 1);

    s = "a";
    assert(so->minCut(s) == 0);

    s = "ab";
    assert(so->minCut(s) ==1);

    s = "ababababababababababababcbabababababababababababa";
    std::cout << so->minCut(s) << std::endl; // timeout
}
