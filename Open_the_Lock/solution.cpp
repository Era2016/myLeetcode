#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using std::vector;
using std::queue;
using std::string;
using std::unordered_set;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> us1, us2;
        unordered_set<string> visit(deadends.begin(), deadends.end());
        
        auto p = visit.insert("0000");
        if (p.second == false) {
            return -1;
        }
        us1.insert("0000");
        us2.insert(target);
        int depth = 0;
        
        while (!us1.empty() && !us2.empty()) {
            // 哈希集合在遍历的过程中不能修改，用 temp 存储扩散结果
            unordered_set<string> tmp;
            // 将us1中的所有节点向周围扩散
            for (auto str: us1) {
                if (visit.find(str) != visit.end()) {
                    continue;
                }
                if (us2.find(str) != us2.end()) {
                    return depth;
                }

                for (int i = 0; i < 4; i ++) {
                    string newAdd = str;
                    newAdd[i] = newAdd[i] == '9'? '0': newAdd[i]+1;
                    if (visit.find(newAdd) == visit.end()) {
                        tmp.insert(newAdd);
                        visit.insert(newAdd);
                    }

                    string newMinus = str;
                    newMinus[i] = newMinus[i] == '0'? '9': newMinus[i]-1;
                    if (visit.find(newMinus) == visit.end()) {
                        tmp.insert(newMinus);
                        visit.insert(newMinus);
                    }
                }
            }
            depth ++;
            
            // tmp 相当于 q1
            // 这里交换 q1 q2，下一轮 while 就是扩散 q2
            us1 = us2;
            us2 = tmp;
            //tmp.clear();
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
    return 1;

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
