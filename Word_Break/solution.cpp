#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::string;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        int maxStringLength = INT_MIN;
        for (auto word: wordDict) {
            maxStringLength = std::max(maxStringLength, (int)word.length()); 
        }
        vector<int> dp(s.length()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i ++) {
            for (int j = std::max(0, i-maxStringLength); j < i; j ++) {
                if (dp[j] && us.find(s.substr(j, i-j)) != us.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> wordDict;

    wordDict = {"leet","code"};
    std::cout << so->wordBreak("leetcode", wordDict) << std::endl;

    wordDict = {"apple","pen"};
    std::cout << so->wordBreak("applepenapple", wordDict) << std::endl;

    wordDict = {"cats","dog","sand","and","cat"};
    std::cout << so->wordBreak("catsandog", wordDict) << std::endl;

    wordDict = {"a","abc","b","cd"};
    std::cout << so->wordBreak("abcd", wordDict) << std::endl;

    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}; // timeout
    std::cout << so->wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict) << std::endl;

}
