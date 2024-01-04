#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int dp(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        if (i < 0 || j < 0 || j >= matrix[0].size()) {
            return INT_MAX;
        }
        if (i == 0) return matrix[0][j];
        if (memo[i][j] != INT_MAX) return memo[i][j];
        memo[i][j] = matrix[i][j] + 
            std::min(std::min(dp(matrix, i-1, j-1, memo), 
                        dp(matrix, i-1, j, memo)), 
                    dp(matrix, i-1, j+1, memo));
        return memo[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        vector<vector<int>> memo(m+1, vector<int>(n+1, INT_MAX));
        for (int j = 0; j <= n; j ++) {
            minSum = std::min(minSum, dp(matrix, m, j, memo));
        }
        return minSum;
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
