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
    string lock_add(string lock, int index) {
        char arr[lock.length() + 1];
        lock.copy(arr, lock.length() + 1);
        std::cout << string(arr) << std::endl;
        if (arr[index] == '9') {
            arr[index] = '0';
        } else {
            arr[index]++;
        }
        std::cout << string(arr) << std::endl;
        return string(arr);
    }
    string lock_minus(string lock, int index) {
        char arr[lock.length() + 1];
        lock.copy(arr, lock.length() + 1);
        if (arr[index] == '0') {
            arr[index] = '9';
        } else {
            arr[index]--;
        }
        return string(arr);
    }

public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> us;
        for (auto val: deadends)  us.insert(val);

        q.push("0000");
        us.insert("0000");
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                string lock = q.front(); q.pop();
                if (lock == target) {
                    return step;
                }
                for (int j = 0; j < 4; j ++) {
                    string newAdded = lock_add(lock, j);
                    if (us.find(newAdded) == us.end()) {
                        q.push(newAdded);
                        us.insert(newAdded);
                    }

                    string newMinus = lock_minus(lock, j);
                    if (us.find(newMinus) == us.end()) {
                        q.push(newMinus);
                        us.insert(newMinus);
                    }
                }
            }// end of for
            step ++;
        } // end of while
        return -1;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> deadends;
    string target;

    deadends = {"0201","0101","0102","1212","2002"};
    target = "0202";
    //std::cout << target << ":" << target.length()<<  std::endl;
    so->lock_add(target, 0);

    return 1;
    std::cout << so->openLock(deadends, target) << std::endl;

    deadends = {"8888"};
    target = "0009";
    std::cout << so->openLock(deadends, target) << std::endl;
}
