#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        //if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0;
        if (s.empty() ) return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < (int)dp.size(); ++i) {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        
        for (vector<int>::iterator iter = dp.begin(); iter != dp.end(); ++ iter) {
            cout << *iter << endl;
        }
        return dp.back();
    }
};

int main()
{
    Solution* so = new Solution();
    cout << so->numDecodings("112024") << endl;
    return 0;
}
