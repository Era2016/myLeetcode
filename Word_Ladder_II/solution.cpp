#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::vector;
using std::queue;
using std::unordered_map;
using std::unordered_set;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
            vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {};
        dict.erase(beginWord);

        vector<vector<string>> res;
        unordered_map<string, int> um = {{beginWord, 0}}; // key->step
        unordered_map<string, unordered_set<string>> from = {{beginWord, {}}}; // key->parent
        queue<string> q; q.push(beginWord);
        int wordSize = beginWord.size();
        bool found = false;
        int step = 0;
        while (!q.empty()) {
            step ++;
            int size = q.size();
            for (int cnt = 0; cnt < size; cnt ++) {
                string origin = q.front(); q.pop();
                for (int i = 0; i < wordSize; i ++) {
                    string nextWord = origin;
                    for (char c = 'a'; c <= 'z'; c ++) {
                        nextWord[i] = c;
                        if (um[nextWord] == step) {
                            from[nextWord].insert(origin);
                        }
                        if (dict.find(nextWord) == dict.end()) continue;

                        dict.erase(nextWord);
                        from[nextWord].insert(origin);
                        um[nextWord] = step;
                        if (nextWord == endWord) found = true;
                        q.push(nextWord);
                    }
                }
            }
            if (found) break;
        }
        if (found) {
            vector<string> path = {endWord};
            backtrack(res, endWord, from, path);
        }
        return res;
    }

    void backtrack(vector<vector<string>>& res,
            const string& node,
            unordered_map<string, unordered_set<string>>& from,
            vector<string>& path) {

        if (from[node].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string& parent: from[node]) {
            path.push_back(parent);
            backtrack(res, parent, from, path);
            path.pop_back();
        }
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> v;
    vector<vector<string>> vv;
    auto print=[&]() {
        for (auto &arr: vv) {
            for (auto &val: arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    };

    v = {"hot","dot","dog","lot","log","cog"};
    vv = so->findLadders("hit", "cog", v);
    print();

    v = {"hot","dot","dog","lot","log"};
    vv = so->findLadders("hit", "cog", v);
    print();

    v = {"a","b","c"};
    vv = so->findLadders("a", "c", v);
    print();
}
