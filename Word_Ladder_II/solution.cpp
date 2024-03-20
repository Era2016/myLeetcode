#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>

using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::string;
using std::queue;
using std::deque;

class Solution {
private:
    unordered_set<string> filter;
    // change word
    unordered_set<string> updateWord(string& origin) {
        unordered_set<string> res;
        for (int i = 0; i < origin.length(); i ++) {
            string newStr = origin;
            for (char c = 'a'; c <= 'z'; c ++) {
                newStr[i] = c;
                if (filter.find(newStr) != filter.end()) {
                    res.insert(newStr);
                }
            }
        }
        return res;
    }
    
    // bfs(queue)
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->filter = unordered_set<string>(wordList.begin(), wordList.end());
        unordered_map<int, unordered_set<string>> records; // depth->set
        unordered_map<string, unordered_set<string>> childSet; // root->childSet

        deque<string> q;
        q.push_back(beginWord);
        int depth = 1;
        bool found = false;
        while (!q.empty()) {
            for (int i = 0; i < q.size(); i ++) {
                string word = q.front(); q.pop_front();
                unordered_set<string> newWords = updateWord(word);
                records[depth] = newWords; 
                if (newWords.find(endWord) != newWords.end()) {
                    found = true;
                }
                if (childSet.find(word) == childSet.end()) {
                    childSet[word] = newWords;
                }
            }
            for (auto val: records[depth]) {
                q.push_back(val);
            }

            if (found) break;
            depth ++;
        }

        if (!found) return {};
        
    }
};

int main() {
    return 1;
}