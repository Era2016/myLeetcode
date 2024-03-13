#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        for (int i = 0; i <= rowIndex; i ++) {
            res[0] = res[i] = 1;
            for (int j = i-1; j > 0; j --) {
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> res;

    auto print=[&]() {
        for (const auto& val: res) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    };

    res = so->getRow(5);
    print();

    res = so->getRow(7);
    print();
}
