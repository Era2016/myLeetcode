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
        //vector<vector<int> > memo (n+1, vector<int>(n+1, 0)); 
        //return count(memo, 1, n);
        return countNumber(n);
    }

    int countNumber(int n) {
        if (n == 0 || n == 1) return 1;

        if (um.count(n) > 0) return um[n];

        int res = 0;
        for (int i = 1; i <= n; i ++) {
            int left = countNumber(i-1);
            int right = countNumber(n-i);
            res += left * right;
        }

        um[n] = res;
        return res;
    }

    int count(vector<vector<int> >& memo, int lo, int hi) {
        if (lo > hi) return 1;

        if (memo[lo][hi] != 0) return memo[lo][hi];

        int res = 0;
        for (int mid = lo; mid <= hi; mid ++) {
            int left = count(memo, lo, mid-1);
            int right = count(memo, mid+1, hi);

            res += left*right;
        }

        memo[lo][hi] = res;
        return res;
    }
};

int main() {
    Solution* so = new Solution();
    std::cout << "n=3: " << so->numTrees(3) << std::endl;
    std::cout << "n=5: " << so->numTrees(5) << std::endl;
    std::cout << "n=1: " << so->numTrees(1) << std::endl;
    std::cout << "n=19: " << so->numTrees(19) << std::endl;
}
