#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int uniquePaths(int m, int n) {
			vector<vector<int> > dp(m, vector<int>(n, 1));
			//print(dp);
			for (int i = 1; i < m; i++) {
				for (int j = 1; j < n; j++) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
			return dp[m - 1][n - 1];
		}

		int uniquePaths2(int m, int n) {
			vector<int> pre(n, 1), cur(n, 1);
			for (int i = 1; i < m; i++) {
				for (int j = 1; j < n; j++) {
					cur[j] = pre[j] + cur[j - 1];
				}
				swap(pre, cur);
			}
			return pre[n - 1];
		}

		int uniquePaths3(int m, int n) {
			vector<int> cur(n, 1);
			for (int i = 1; i < m; i++) {
				for (int j = 1; j < n; j++) {
					cur[j] += cur[j - 1];
				}
			}
			return cur[n - 1];
		}

		void print(vector<vector<int> > vv) {
			for (int i = 0; i < (int)vv.size(); i++) {
				for (int j = 0; j < (int)vv[i].size(); j ++) {
					cout << vv[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl;
		}
};

int main() {
	//vector<int> dp = vector<int>(10, 1);
	//for (int i = 0; i < (int)dp.size(); i ++) {
	//	cout << dp[i] << "\t";
	//}
	//cout << endl;
	Solution* so = new Solution();
	//so->uniquePaths(7, 3);
	cout << "(3, 2) result: " << so->uniquePaths(3, 2) << endl;
	cout << "(7, 3) result: " << so->uniquePaths(7, 3) << endl;
	cout << "(1, 1) result: " << so->uniquePaths(1, 1) << endl;
}
