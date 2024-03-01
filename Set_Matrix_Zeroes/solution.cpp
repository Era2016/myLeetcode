#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool col = false;
        for (int i = 0; i < m; i ++) {
            if (!matrix[i][0]) {
                col = true;
            }
            for (int j = 1; j < n; j ++) {
                if (!matrix[i][j]) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }

        for (int i = m-1; i >= 0; i --) {
            for (int j = 1; j < n; j ++) {
                if (!matrix[0][j] || !matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }
            if (col) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> matrix;
    auto print=[&]() {
        for (auto arr: matrix) {
            for (auto v: arr) {
                std::cout << v << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    };

    matrix = {{1,1,1},{1,0,1},{1,1,1}};
    so->setZeroes(matrix);
    print();

    matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    so->setZeroes(matrix);
    print();
}
