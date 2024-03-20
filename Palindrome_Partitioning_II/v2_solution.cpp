#include <climits>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::string;
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp1(n, vector<int>(n, 1));
        for (int i = n - 1; i >= 0; i --) {
            for (int j = i + 1; j < n; j ++) {
                dp1[i][j] = (s[i] == s[j]) && dp1[i+1][j-1];
            }
        }

        // dp[i], 0...i的最小分段数
        // dp[i] = 0, 0...i是回文
        //       = dp[j]+1，j...i是回文字符串
        vector<int> dp2(n, INT_MAX);
        for (int i = 0; i < n; i ++) {
            if (dp1[0][i]) {
                dp2[i] = 0;
            } else {
                // j...i 不是回文
                for (int j = 0; j < i; j ++) {
                    if (dp1[j+1][i]) {
                        dp2[i] = std::min(dp2[i], dp2[j]+1); 
                    }
                }
            }
        }
        return dp2[n-1];
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
