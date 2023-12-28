#include <climits>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    // timeout: lots of replicated calculation
    void backtrack(vector<vector<int>>& grid, int i, int j, int& cnt) {
        //std::cout << "cur: " << i << "*" << j << "\n";
        if (i == grid.size()-1 && j == grid[0].size()-1) {
            if (grid[i][j] != 1) 
                cnt ++;
            return;
        }
        
        if (i == grid.size()) return;
        if (j == grid[0].size()) return;
        
        if (grid[i][j] == 1) {
            return;
        }
        backtrack(grid, i+1, j, cnt);
        backtrack(grid, i, j+1, cnt);
        return;
    }

    int dp(vector<vector<int>> &grid, int m, int n, vector<vector<int>>& memo) {
        if (grid[m][n] == 1) {
            memo[m][n] = 0;
            return 0;
        }

        if (memo[m][n] != INT_MAX) {
            return memo[m][n];
        }
        if (m == 0) {
            for (int i = 0; i <= n; i ++) {
                if (grid[0][i] == 1) {
                    memo[m][n] = 0;
                    return 0;
                }
            }
            return 1;
        }
        if (n == 0) {
            for (int i = 0; i <= m; i ++) {
                if (grid[i][0] == 1) {
                    memo[m][n] = 0;
                    return 0;
                }
            }
            return 1;
        }
        memo[m][n] = dp(grid, m-1, n, memo) + dp(grid, m, n-1, memo);
        return memo[m][n];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // backtrack
        //int cnt = 0;
        //backtrack(obstacleGrid, 0, 0, cnt);
        //return cnt;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, INT_MAX));
        return dp(obstacleGrid, m-1, n-1, memo);
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
