#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vv(n, vector<int>(n, 0));
        int startRow = 0, startColumn = 0;
        int endRow = n-1, endColums = n-1;
        int cnt = 1;
        while (startRow <= endRow && startColumn <= endColums) {
            for (int j = startColumn; j <= endColums; j ++) {
                vv[startRow][j] = cnt ++;
            }
            startRow ++;

            for (int i = startRow; i <= endRow; i ++) {
                vv[i][endColums] = cnt ++;
            }
            endColums --;

            if (startColumn <= endColums) {
                for (int j = endColums; j >= startColumn; j --) {
                    vv[endRow][j] = cnt ++;
                }
            }
            endRow --;

            if (startRow <= endRow) {
                for (int i = endRow; i >= startRow; i --) {
                    vv[i][startColumn] = cnt ++;
                }
            }
            startColumn ++;
        }

        return vv;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> vv;

    auto print=[](vector<vector<int>>& vv) {
        for (const auto& kv :vv) {
            for (const auto& k: kv) {
                std::cout << k << "\t";
            } 
            std::cout << std::endl;
        }
        std::cout << std::endl;
    };
    vv = so->generateMatrix(3);
    print(vv);

    vv = so->generateMatrix(1);
    print(vv);
}
