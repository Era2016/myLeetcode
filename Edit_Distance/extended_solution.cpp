#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using std::vector;
using std::string;
using std::pair;
class Solution {
public:
    vector<string> minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<pair<int, string>>> dp(m+1, vector<pair<int, string>>(n+1, {0, "nothing"}));
        for (int i = 1; i <= m; i ++) {
            dp[i][0] = {i, "insert"};
        }
        for (int j = 1; j <= n; j ++) {
            dp[0][j] = {j, "delete"};
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j].first = dp[i-1][j-1].first;
                    dp[i][j].second = "nothing";
                } else {
                    int minDis = INT_MAX;
                    string op = "";
                    if (minDis > dp[i][j-1].first) {
                        minDis = dp[i][j-1].first;
                        op = "insert"; 
                    }
                    if (minDis > dp[i-1][j].first) {
                        minDis = dp[i-1][j].first;
                        op = "delete";
                    }
                    if (minDis > dp[i-1][j-1].first) {
                        minDis = dp[i-1][j-1].first;
                        op = "replace";
                    }
                    dp[i][j] = {minDis+1, op};
                }
            }
        }

        vector<string> res;
        int i = m, j = n;
        while (i != 0 || j != 0) {
            if (dp[i][j].second == "delete") {
                i = i-1;
            } else if (dp[i][j].second == "insert") {
                j = j-1;
            } else { // nothing/replace
                i = i-1; j = j-1;
            }
            res.push_back(dp[i][j].second);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

};

int main() {
    Solution *so = new Solution();
    vector<string> res;
    std::for_each(res.begin(), res.end(), [](const string& str){
            std::cout << str << std::endl; 
            });

    res = so->minDistance("horse", "ros"); 
    res = so->minDistance("intention", "execution");
}
