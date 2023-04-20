#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int rows = grid.size();
        int columns = grid[0].size();
        auto dp = vector<vector<int>>(rows, vector<int>(columns, -1));
        
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i ++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for (int j = 1; j < columns; j ++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for (int i = 1; i < rows; i ++) {
            for (int j = 1; j < columns; j ++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[rows-1][columns-1];
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
