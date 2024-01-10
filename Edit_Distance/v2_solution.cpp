#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    // 原生：超出内存限制
    // 定义：返回 s1[0..i] 和 s2[0..j] 的最小编辑距离
    vector<vector<int>> memo;
    int dp(string word1, int i, string word2, int j) {
        if (i == -1) return j+1;
        if (j == -1) return i+1;

        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (word1[i] == word2[j]) {
            memo[i][j] = dp(word1, i-1, word2, j-1); // 啥都不做
            return memo[i][j];
        }

        memo[i][j] = std::min(
                std::min(dp(word1, i, word2, j-1)+1, // word1插入
                    dp(word1, i-1, word2, j)+1),     // word1删除
                dp(word1, i-1, word2, j-1)+1         // word1/2替换
                );
        return memo[i][j];
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

    std::cout << so->minDistance("horse", "ros") << std::endl; // 3
    std::cout << so->minDistance("intention", "execution") << std::endl; // 5
    std::cout << so->minDistance("dinitrophenylhydrazine", "benzalphenylhydrazone") << std::endl; // 7
}
