#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			if (p[i - 1] == '*') {
				dp[0][i] = dp[0][i - 1];
			}
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				} else {
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}

	bool isMatch_v2(char *s, char *p) {
		char *scur = s, *pcur = p, *sstar = NULL, *pstar = NULL;
		while (*scur) {
			if (*scur == *pcur || *pcur == '?') {
				++scur;
				++pcur;
			} else if (*pcur == '*') {
				pstar = pcur++;
				sstar = scur;
			} else if (pstar) {
				pcur = pstar + 1;
				scur = ++sstar;
			} else return false;
		} 
		while (*pcur == '*') ++pcur;
		return !*pcur;
	}
};

int main()
{
	Solution* so = new Solution();
	cout << so->isMatch("hello world", "hello*ld") << endl;
	return 0;
}
