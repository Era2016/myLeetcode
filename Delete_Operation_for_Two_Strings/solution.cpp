#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    vector<vector<int>> memo;
    int dp(string word1, int m, string word2, int n) {
        if (m == -1) return n+1;
        if (n == -1) return m+1;

        if (memo[m][n] != -1) {
            return memo[m][n];
        }

        if (word1[m] == word2[n]) {
            memo[m][n] = dp(word1, m-1, word2, n-1);
        } else {
            memo[m][n] = 1+std::min(dp(word1, m-1, word2, n), dp(word1, m, word2, n-1));
        }
        return memo[m][n];
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        this->memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(word1, m-1, word2, n-1);
    }
};

int main() {
    Solution *so = new Solution();
    
    std::cout << so->minDistance("sea", "eat") << std::endl; // 2
    std::cout << so->minDistance("leetcode", "etco") << std::endl; // 4
    std::cout << so->minDistance("dinitrophenylhydrazine", "benzalphenylhydrazone") << std::endl; // 13
}
