#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j ++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->uniquePaths(3, 7) << std::endl; // 28
    std::cout << so->uniquePaths(3, 2) << std::endl; // 3 
    std::cout << so->uniquePaths(7, 3) << std::endl; // 28 
    std::cout << so->uniquePaths(3, 3) << std::endl; // 6 
}
