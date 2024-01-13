#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = 0; j < n; j ++) {
            dp[0][j] = matrix[0][j];
        }
        
        int minVal = INT_MAX;
        for (int i = 1; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (j == 0) {
                    dp[i][j] = std::min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                } else if (j == n-1) {
                    dp[i][j] = std::min(dp[i-1][j-1], dp[i-1][j]) + matrix[i][j];
                } else {
                    dp[i][j] = std::min(std::min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]) + matrix[i][j];
                }
            }
        }
        for (int j = 0; j < n; j ++) {
            minVal = std::min(minVal, dp[m-1][j]);
        }
        return minVal;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> vv;
    
    vv = {{2,1,3},{6,5,4},{7,8,9}};
    std::cout << so->minFallingPathSum(vv) << std::endl;

    vv = {{-19,57},{-40,-5}};
    std::cout << so->minFallingPathSum(vv) << std::endl;
}
