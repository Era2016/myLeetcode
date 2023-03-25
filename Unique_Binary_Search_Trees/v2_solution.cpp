#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
class Solution {
private:
    unordered_map<int, int> um;
public:
    int numTrees(int n) {
        //vector<vector<int> > memo (n+2, vector<int>(n+2, 0)); 
        //return count(memo, 1, n);
        return countNumber(n);
    }

    // 堆溢出错误
    int countNumber(int n) {
        if (n == 0 || n == 1) return 1;

        if (um.count(n) > 0) return um[n];

        int res = 0;
        for (int i = 1; i <= n; i ++) {
            int left = countNumber(i-1);
            int right = countNumber(i+1);
            res += left * right;
        }

        um[n] = res;
        return res;
    }

    // 堆溢出错误
    int count(vector<vector<int> >& memo, int left, int right) {
        if (left > right) return 1;

        if (memo[left][right] != 0) return memo[left][right];

        int res = 0;
        for (int mid = left; mid <= right; mid ++) {
            int left = count(memo, left, mid-1);
            int right = count(memo, mid+1, right);

            res += left*right;
        }

        memo[left][right] = res;
        return res;
    }
};

int main() {
    Solution* so = new Solution();
    std::cout << "n=3: " << so->numTrees(3) << std::endl;
    //std::cout << "n=5: " << so->numTrees(5) << std::endl;
    //std::cout << "n=1: " << so->numTrees(1) << std::endl;
    //std::cout << "n=19: " << so->numTrees(19) << std::endl;
}
