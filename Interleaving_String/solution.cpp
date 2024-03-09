#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length();
        int len3 = s3.length();
        if (len3 != len1+len2) return false;

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        dp[0][0] = true;
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                if (i>0 && s3[i+j-1]==s1[i-1]) {
                    dp[i][j] |= dp[i-1][j];
                }

                if (j>0 && s3[i+j-1]==s2[j-1]) {
                    dp[i][j] |= dp[i][j-1];
                }
            }
        }
        return dp[len1][len2];
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->isInterleave("aabcc", "dbbca", "aadbbcbcac") << std::endl;
    std::cout << so->isInterleave("aabcc", "dbbca", "aadbbbaccc") << std::endl;
    std::cout << so->isInterleave("", "", "") << std::endl;
}
