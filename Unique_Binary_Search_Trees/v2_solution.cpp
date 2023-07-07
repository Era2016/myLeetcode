#include <iostream>
#include <vector>

#include "../utils/binaryTree.h"
using std::vector;
class Solution {
private:
    vector<vector<int>> memo;
    int build(int low, int high) {
        if (low > high) {
            return 1;
        }
        if (memo[low][high]) return memo[low][high];

        int cnt = 0;
        for (int i = low; i <= high; i ++) {
            int leftCnt = build(low, i-1);
            int rightCnt = build(i+1, high);
            cnt += leftCnt * rightCnt;
        }

        memo[low][high] = cnt;
        return cnt;
    }
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        this->memo.resize(n+1, vector<int>(n+1));
        return build(1, n);
    }
};

int main() {
    Solution *so = new Solution();

    std::cout << so->numTrees(3) << std::endl;
    std::cout << so->numTrees(1) << std::endl;
}
