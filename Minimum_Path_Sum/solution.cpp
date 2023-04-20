#include <iostream>
#include <vector>
#include <algorithm> // max

using std::vector;
using std::min;

class Solution {
private:
    vector<vector<int>> memo;
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(grid, m - 1, n - 1);
    }

    int dp(vector<vector<int>> grid, int i, int j) {
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        if (i < 0 || j < 0) {
            return INT_MAX;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = min(dp(grid, i-1, j), dp(grid, i, j-1)) + grid[i][j];
        return memo[i][j];
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> vv; 

    vv = {{1,3,1}, {1,5,1}, {4,2,1}};
    std::cout << so->minPathSum(vv) << std::endl;
    
    vv = {{1,2,3}, {4,5,6}};
    std::cout << so->minPathSum(vv) << std::endl;
}
