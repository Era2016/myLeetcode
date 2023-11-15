#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int m, n;
    vector<vector<int>> memo;
    int backtrack(vector<vector<int>>& grid, int _r, int _c) {
        //std::cout << _r << ":" << _c << std::endl;
        if (_r == m-1 && _c == n-1) {
            if (grid[_r][_c]) return 0;
            return 1;
        }
        
        if (grid[_r][_c] == 1) {
            return 0;
        }
        if (memo[_r][_c]) {
            return memo[_r][_c];
        }

        int cnt = 0;
        if (_r+1 < m) {
            cnt += backtrack(grid, _r+1, _c);
        }
        
        if (_c+1 < n) {
            cnt += backtrack(grid, _r, _c+1);
        }
        
        memo[_r][_c] = cnt;
        return memo[_r][_c];;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return 0;
        }
        this->m = obstacleGrid.size();
        this->n = obstacleGrid[0].size();
        this->memo = vector<vector<int>>(this->m, vector<int>(this->n, 0));
        return backtrack(obstacleGrid, 0, 0);
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
}