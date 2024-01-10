#include <iostream>
#include <vector>

using std::vector;
using std::string;
class Solution {
private:
    //  定义：返回 s1[0..i] 和 s2[0..j] 的最小编辑距离
    int dp(string word1, int i, string word2, int j) {
        if (i == -1) return j+1;
        if (j == -1) return i+1;

        if (word1[i] == word2[j]) {
            return dp(word1, i-1, word2, j-1); // 啥都不做
        }

        return std::min(
                std::min(dp(word1, i, word2, j-1)+1, // word1插入
                    dp(word1, i-1, word2, j)+1),     // word1删除
                dp(word1, i-1, word2, j-1)+1         // word1/2替换
                );
    }
public:
    int minDistance(string word1, string word2) {
        return dp(word1, word1.length()-1, word2, word2.length()-1);
    }
};

int main() {
    Solution *so = new Solution();

    std::cout << so->minDistance("horse", "ros") << std::endl; // 3
    std::cout << so->minDistance("intention", "execution") << std::endl; // 5
}
