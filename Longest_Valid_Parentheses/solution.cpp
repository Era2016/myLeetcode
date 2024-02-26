#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::max;

class Solution {
public:
    /**
     * dp[i] 表示以下标i 字符结尾的最长有效括号的长度
     * dp[i] = dp[i-2] + 2  ".......()"
     * dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2  "........))"
     * s[i-dp[i-1]] 一定为'('，根据dp[i-1]含义，如果s[i-dp[i-1]-1]
     * 也是'('，此时已和i匹配成功，最后再加上前一位的dp结果即可，即
     * dp[i-dp[i-1]-2]
     * */
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2? dp[i-2]: 0) + 2;
                } else if (i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') {
                    dp[i] = dp[i-1] + (((i-dp[i-1]) >= 2)? dp[i-dp[i-1]-2]: 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

int main() {
    Solution* so = new Solution();
    string s;

    s = "(()";
    std::cout << so->longestValidParentheses(s) << std::endl; // 2

    s = ")()())";
    std::cout << so->longestValidParentheses(s) << std::endl; // 4

    s = "";
    std::cout << so->longestValidParentheses(s) << std::endl; // 0

}
