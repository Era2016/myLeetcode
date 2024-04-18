#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
private:
    unordered_map<int, bool> um;
    bool calulate(int num) {
        unordered_set<int> us;
        while (true) {
            vector<int> v;
            while (num) {
                v.push_back(num%10);
                num /= 10;
            }

            for (auto n: v) {
                num += n*n;
            }

            if (num == 1) {
                return true;
            }
            if (us.find(num) != us.end()) {
                return false;
            }

            us.insert(num);
        }
    }
public:
    Solution() {
        // int整数最大值为2^31, 约20亿，结果集最大值为1999999999
        for (int i = 1; i < 81*9+1; i ++) {
            um[i] = calulate(i);
        }
    }

    bool justify(int num) {
        return um[num]; 
    }
};

int main() {
    Solution *so = new Solution();

    for (int i = 1; i < 81*9+1; i ++) {
        std::cout << i << " " << so->justify(i) << std::endl;
    }
}
