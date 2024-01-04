#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
class Solution {
private:
    bool backtrack(string s, int index, vector<string>& wordDict) {
        if (index == s.length()) { return true; }
        for (auto &str: wordDict) {
            if (s.substr(index, str.length()) == str) {
                if (backtrack(s, index+str.length(), wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end(),
                [](const string s1, const string s2) {
                    return s1.length() > s2.length();
                });
        
        return backtrack(s, 0, wordDict);
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
