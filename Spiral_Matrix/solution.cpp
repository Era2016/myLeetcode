#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int row = matrix.size()-1;
        int column = matrix[0].size()-1;

        vector<int> v;
        int startRow = 0, startColumn = 0;
        while (startRow <= row && startColumn <= column) {
            for (int j = startColumn; j <= column; j ++) {
                v.push_back(matrix[startRow][j]);
            }
            startRow ++;

            for (int i = startRow; i <= row; i ++) {
                v.push_back(matrix[i][column]);
            }
            column --;

            if (startRow <= row) {
                for (int j = column; j >= startColumn; j --) {
                    v.push_back(matrix[row][j]);
                }
            }
            row --;

            if (startColumn <= column) {
                for (int i = row; i >= startRow; i --) {
                    v.push_back(matrix[i][startColumn]);
                }
            }
            startColumn ++;
        }
        return v;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> vv;
    vector<int> v;
    auto print=[](vector<int>& v) {
        for (const auto& i: v) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
    };
    vv = {{1,2},{3,4}};
    v = so->spiralOrder(vv);
    print(v);

    vv = {{1,2,3},{4,5,6},{7,8,9}};
    v = so->spiralOrder(vv);
    print(v);

    vv = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    v = so->spiralOrder(vv);
    print(v);
}
