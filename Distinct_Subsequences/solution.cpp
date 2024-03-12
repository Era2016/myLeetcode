#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 0; i <= m; i ++) dp[i][0] = 1;
        for (int j = 1; j <= n; j ++) dp[0][j] = 0;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = (unsigned long)dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->numDistinct("rabbbit", "rabbit") << std::endl; // 3
    std::cout << so->numDistinct("babgbag", "bag") << std::endl; // 5
    std::cout << so->numDistinct("", "") << std::endl;
}
