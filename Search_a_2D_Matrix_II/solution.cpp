#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] > target) {
                j --;
            } else if (matrix[i][j] < target) {
                i ++;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> matrix;

    matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    std::cout << so->searchMatrix(matrix, 5) << std::endl;

    matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    std::cout << so->searchMatrix(matrix, 20) << std::endl;
}
