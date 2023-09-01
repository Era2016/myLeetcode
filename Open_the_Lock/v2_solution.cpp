#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using std::vector;
using std::unordered_set;
using std::string;
using std::queue;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> us(deadends.begin(), deadends.end());
        auto p = us.insert("0000");
        if (p.second == false) return -1;
        q.push("0000");

        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                string str = q.front(); q.pop();
                if (str == target) {
                    return depth;
                }
                for (int j = 0; j < 4; j ++) {
                    string newAdd = str;
                    char c = newAdd[j];
                    c = (c == '9')? '0': c+1;
                    newAdd[j] = c;
                    //std::cout << newAdd << ":add:" << str << std::endl;
                    if (us.find(newAdd) == us.end()) {
                        us.insert(newAdd);
                        q.push(newAdd);
                    }

                    string newMinus = str;
                    c = newMinus[j];
                    c = (c == '0')? '9': c-1;
                    newMinus[j] = c;
                    //std::cout << newMinus << ":minus:" << str << std::endl;
                    if (us.find(newMinus) == us.end()) {
                        us.insert(newMinus);
                        q.push(newMinus);
                    }
                }
            }
            depth ++;
        }
        return -1;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> deadends;
    string target;

    deadends = {"0201","0101","0102","1212","2002"};
    target = "0202";
    std::cout << so->openLock(deadends, target) << std::endl;

    deadends = {"8888"};
    target = "0009";
    std::cout << so->openLock(deadends, target) << std::endl;

    deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    target = "8888";
    std::cout << so->openLock(deadends, target) << std::endl;

    deadends = {"0000"};
    target = "8888";
    std::cout << so->openLock(deadends, target) << std::endl;
}