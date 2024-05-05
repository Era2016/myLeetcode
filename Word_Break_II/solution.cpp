#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
private:
    unordered_map<string, vector<string>> um;
    vector<string> backtrack(string s, unordered_set<string>& wordDict, int idx) {
        if (idx == s.length()) {
            return {""};
        }

        vector<string> v;
        for (auto word: wordDict) {
            if (s.substr(idx, word.size()) == word) {
                if (um.find(word) != um.end()) {
                    return um[word];
                }
                vector<string> sub = backtrack(s, wordDict, idx+word.size());
                for (auto ss: sub) {
                    v.push_back(word+(ss.empty()? "": " "+ss));
                }
            }
        }
        um[s] = v;
        return v;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        return backtrack(s, us, 0);
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v, res;
    auto print=[](vector<string>& vv) {
        for (auto v: vv) {
            std::cout << v << std::endl;
        }
        std::cout << std::endl;
    };

    v = {"cat","cats","and","sand","dog"};
    res = so->wordBreak("catsanddog", v);
    print(res);

    v = {"apple","pen","applepen","pine","pineapple"}; 
    res = so->wordBreak("pineapplepenapple", v);
    print(res);

    v = {"cats","dog","sand","and","cat"}; 
    res = so->wordBreak("catsandog", v);
    print(res);
}
