#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    /*
    f(i, j) = f(i-1, j) + f(i, j-1), (i,j)==0
    f(i, j) = 0,                     (i,j)!=0
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid.at(0).size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] != 1; i ++) dp[i][0] = 1;
        for (int i = 0; i < n && obstacleGrid[0][i] != 1; i ++) dp[0][i] = 1;

        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] != 0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> grid;

    grid = {{0,0,0},{0,1,0},{0,0,0}};
    std::cout << so->uniquePathsWithObstacles(grid) << std::endl;

    grid = {{0,1},{0,0}};
    std::cout << so->uniquePathsWithObstacles(grid) << std::endl;

    grid = {{0,0},{0,1}};
    std::cout << so->uniquePathsWithObstacles(grid) << std::endl;

    grid = {{0,0}};
    std::cout << so->uniquePathsWithObstacles(grid) << std::endl;
}