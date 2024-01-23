#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        // base case
        for (int i = 0; i < m; i ++) {
            dp[i][i] = 1;
        }
        // 反着遍历保证正确的状态转移
        for (int i = m-1; i >= 0; i --) {
            for (int j = i+1; j < m; j ++) {
                //if (j == m) std::cout << "strange !" << std::endl;
                // 状态转移方程
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2; // j != m, dp不会溢出 
                } else {
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][m-1];
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->longestPalindromeSubseq("bbbab") << std::endl; // 4
    std::cout << so->longestPalindromeSubseq("cbbd") << std::endl; // 2
}
