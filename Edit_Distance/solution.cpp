#include <iostream>
#include <vector>

using std::string;
using std::vector;
class Solution {
public:
    /*
     * dp[i][j]: A的前i个字母和B的前j个字母之间的编辑距离(数组下标从1开始)
     * dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1)  word1[i-1] != word2[j-1]
     * dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1])    word1[i-1] == word2[j-1]
     */
    int minDistance(string word1, string word2) {
        int row = word1.length(), column = word2.length();
        vector<vector<int>> dp(row+1, vector<int>(column+1, 0));
        for (int j = 0; j <= column; j ++) dp[0][j] = j;
        for (int i = 0; i <= row; i++) dp[i][0] = i;

        for (int i = 1; i <= row; i ++) {
            for (int j = 1; j <= column; j ++) {
                if (word1[i-1] != word2[j-1]) {
                    dp[i][j] = 1+std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                } else {
                    //dp[i][j] = std::min(std::min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]); 
                    dp[i][j] = 1+std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]-1); 
                }
            }
        }
        //print(dp);
        return dp[row][column];
    }

    void print(vector<vector<int>>& vv) {
        for (auto arr: vv) {
            for (auto v: arr) {
                std::cout << v << "\t";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Solution *so = new Solution();

    std::cout << so->minDistance("horse", "ros") << std::endl;
    std::cout << so->minDistance("intention", "execution") << std::endl;
}
