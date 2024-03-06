#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i ++) {
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            if (i>1 && s[i-2]!='0' && 10*(s[i-2]-'0')+(s[i-1]-'0') <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution *so = new Solution();
    string s;

    s = "12";
    std::cout << so->numDecodings(s) << std::endl;

    s = "226";
    std::cout << so->numDecodings(s) << std::endl;

    s = "06";
    std::cout << so->numDecodings(s) << std::endl;

    s = "11106";
    std::cout << so->numDecodings(s) << std::endl;

    s = "00000";
    std::cout << so->numDecodings(s) << std::endl;

    s = "111111111111111111111111111111111111111111111";
    std::cout << so->numDecodings(s) << std::endl;
}
