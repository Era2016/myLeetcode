#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    // dp(i,j) 表示以(i,j)为右下角，且只包含 1 的正方形的边长最大值
    // dp[i][j] = std::min(dp[i-1][j], std::min(dp[i-1][j-1], dp[i][j-1])) + 1;
    //
    // 边界条件：如果i和j中至少有一个为0，则以位置(i,j)为右下角的最大正方形的边长只能是1，
    // 因此 dp(i,j)=1
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(column));
        int maxSide = 0;
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < column; j ++) {
                if (matrix[i][j] == '1') {
                    if (i == 0|| j == 0) {
                        dp[i][j] = 1;;
                    } else {
                        dp[i][j] = std::min(dp[i-1][j], std::min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    }

                    maxSide = std::max(maxSide, dp[i][j]);
                }
            } // endOfColumn
        } // endOfRow

        return maxSide*maxSide;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<char>> matrix;

    matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };
    std::cout << so->maximalSquare(matrix) << std::endl;

    matrix = {
        {'0','1'},
        {'1','0'},
    };
    std::cout << so->maximalSquare(matrix) << std::endl;
}
