// timeout
#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    int m, n;
    int calc = 0;
    bool backtrack(vector<vector<int>>& grid, vector<vector<bool>> visited, int _r, int _c) {
        //std::cout << _r << ":" << _c << std::endl;
        if (_r == m-1 && _c == n-1 && grid[_r][_c] != 1) {
            calc ++;
            return true;
        }
        
        if (grid[_r][_c] == 1) {
            return false;
        }

        if (_r+1 < m && !visited[_r+1][_c]) {
            visited[_r+1][_c] = true;
            backtrack(grid, visited, _r+1, _c);
            visited[_r+1][_c] = false;
        }
        
        if (_c+1 < n && !visited[_r][_c+1]) {
            visited[_r][_c+1] = true;
            backtrack(grid, visited, _r, _c+1);
            visited[_r][_c+1] = false;
        }
        
        return false;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return 0;
        }
        this->m = obstacleGrid.size();
        this->n = obstacleGrid[0].size();
        this->calc = 0;
        vector<vector<bool>> visit(this->m, vector<bool>(this->n, false));
        backtrack(obstacleGrid, visit, 0, 0);
        return calc;
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