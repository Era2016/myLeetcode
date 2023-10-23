#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Solution {
private:
    bool isValid(vector<string>& v, int row, int column) {
        int n = v.size();
        
        for (int i = 0; i <= row; i ++) {
            if (v[i][column] == 'Q') return false;
        }

        for (int i=row-1, j=column-1; i>=0&&j>=0; i--, j--) {
            if (v[i][j] == 'Q') return false;
        }

        for (int i=row-1, j=column+1; i>=0&&j<n; i--, j++) {
            if (v[i][j] == 'Q') return false;
        }
        return true;
    }
    void backtrack(vector<string>& intermediate, int row, int& total) {
        if (intermediate.size() == row) {
            total ++;
            return;
        }

        int n = intermediate[row].length();
        for (int col = 0; col < n; col ++) {
            if (!isValid(intermediate, row, col)) {
                continue;
            }

            intermediate[row][col] = 'Q';
            backtrack(intermediate, row+1, total);
            intermediate[row][col] = '.';
        }
    }
public:
    int TotalNQueens(int n) {
        vector<string> intermdediate(n, string(n, '.'));
        int total = 0;
        backtrack(intermdediate, 0, total);
        return total;
    }
};

int main() {
    Solution *so = new Solution();
    
    std::cout << so->TotalNQueens(4) << std::endl;
    std::cout << so->TotalNQueens(1) << std::endl;
    std::cout << so->TotalNQueens(9) << std::endl;
}