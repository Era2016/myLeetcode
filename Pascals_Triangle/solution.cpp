#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i ++) {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; j ++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> res;

    auto print=[&]() {
        for (const auto& arr: res) {
            for (const auto& val: arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    };
    
    res = so->generate(10);
    print();
}
