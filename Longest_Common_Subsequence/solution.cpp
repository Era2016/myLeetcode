#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::string;
class Solution {
public:
    // dp[i][j] = dp[i-1][j-1]+1, if text1[i] == text2[j] 
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]), if text1[i] != text2[j]
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //for (int i = 0; i <= m; i ++) {
        //    dp[i][0] = 0;
        //}
        //for (int j = 0; j <= n; j ++) {
        //    dp[0][j] = 0;
        //}
        
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution *so = new Solution();
    
    assert(so->longestCommonSubsequence("abcde", "ace") == 3);
    assert(so->longestCommonSubsequence("abc", "abc") == 3);
    //std::cout << so->longestCommonSubsequence("abc", "def") << std::endl;
    //return 1;
    assert(so->longestCommonSubsequence("abc", "def") == 0);
}
