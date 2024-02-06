#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
public:
    /*
     * dp[i][j] 
     * 1. p[j] != '*'
     *      dp[i][j] = dp[i-1][j-1] (s[i] == p[j])
     *      dp[i][j] = false (else)
     * 2. p[j] == '*'
     *      dp[i][j] = dp[i-1][j] || dp[i][j-2] (s[i] == p[j-1]) [匹配0个、1个/多个]
     *      dp[i][j] = dp[i][j-2] (else) [匹配0个]
     *
     */
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        
        auto matches = [&](int i, int j) {
            if (i == 0) return false;
            if (p[j-1] == '.') return true;
            return s[i-1] == p[j-1];
        };

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = true;
        for (int i = 0; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (p[j-1] == '*') {
                    dp[i][j] |= dp[i][j-2];
                    if (matches(i, j-1)) {
                        dp[i][j] |= dp[i-1][j];
                    }
                } else {
                    if (matches(i, j)) {
                        dp[i][j] |= dp[i-1][j-1];
                    }
                }        
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->isMatch("aa", "a") << std::endl;
    std::cout << so->isMatch("aa", "a*") << std::endl;
    std::cout << so->isMatch("ab", ".*") << std::endl;
}
