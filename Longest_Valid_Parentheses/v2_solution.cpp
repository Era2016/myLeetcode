#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::string;
using std::vector;
using std::stack;
using std::max;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        // dp[i] 的定义：记录以 s[i-1] 结尾的最长合法括号子串长度
        vector<int> dp(s.length()+1, 0);

        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(') {
                st.push(i);
                dp[i+1] = 0;
            } else {
                if (!st.empty()) {
                    // 配对的左括号对应索引
                    int leftIndex = st.top(); st.pop();
                    int len = 1 + i - leftIndex + dp[leftIndex];
                    dp[i+1] = len;
                } else {
                    dp[i+1] = 0;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < dp.size(); i ++) {
            res = max(res, dp[i]);
        }

        return res;
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
