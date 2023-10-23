#include <iostream>
#include <vector>

#include <ctime>

using std::vector;
using std::string;
class Solution {
private:
    vector<vector<string>> result;
    void backtrack(vector<string>& v, int row) {
        if (row == v.size()) {
            result.push_back(v);
            return;
        }

        int n = v[row].length();
        for (int col = 0; col < n; col ++) {
            if (!isValid(v, row, col)) continue;
            
            v[row][col] = 'Q';
            backtrack(v, row+1);
            v[row][col] = '.';
        }
    }
    bool isValid(vector<string>& v, int row, int column) {
        int n = v.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i <= row; i ++) {
            if (v[i][column] == 'Q') return false;
        }

        // 检查右上方是否有皇后互相冲突
        for (int i=row-1, j=column+1; i>=0 && j<n; i --, j ++) {
            if (v[i][j] == 'Q') return false;
        }

        // 检查左上方是否有皇后互相冲突
        for (int i=row-1, j=column-1; i>=0 && j>=0; i --, j --) {
            if (v[i][j] == 'Q') return false;
        }

        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> v(n, string(n,'.'));
        backtrack(v, 0);
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<string>> vv;
    clock_t start, end;

    auto print=[](vector<vector<string>>& vv) {
        for (auto arr: vv) {
            for (auto v: arr) {
                std::cout << v << "\t";
            }
            std::cout << std::endl;
        }
    };

    start = clock();
    vv = so->solveNQueens(4);
    end = clock();
    std::cout << "Spent " << double(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;  // 输出时间（单位：s）

    //print(vv);

    start = clock();
    vv = so->solveNQueens(8);
    end = clock();
    std::cout << "Spent " << double(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;  // 输出时间（单位：s）

    start = clock();
    vv = so->solveNQueens(9);
    end = clock();
    std::cout << "Spent " << double(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;  // 输出时间（单位：s）

    start = clock();
    vv = so->solveNQueens(10);
    end = clock();
    std::cout << "Spent " << double(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;  // 输出时间（单位：s）
}
