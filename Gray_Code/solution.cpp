#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.reserve(1<<n);
        res.emplace_back(0);
        for (int i = 0; i < n; i ++) {
            int size = res.size();
            for (int j = size-1; j >= 0; j --) {
                res.emplace_back(res[j]| (1 << i));
            }
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> res;
    auto print=[](vector<int> v) {
        for (const auto& num: v) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    };

    res = so->grayCode(2);
    print(res);

    res = so->grayCode(3);
    print(res);
}
