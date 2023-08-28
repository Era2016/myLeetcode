#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& combine, int k, int n, int idx) {
        if (n < 0)  {
            return;
        } else if (n == 0) {
            if (combine.size() == k) {
                result.push_back(combine);
            }
            return;
        } else {
            if (combine.size() >= k) return;
            for (int i = idx; i <= 9; i ++) {
                combine.push_back(i);
                backtrack(combine, k, n-i, i+1);
                combine.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combine;
        result.clear();
        
        backtrack(combine, k, n, 1);
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> res;

    auto print=[](vector<vector<int>>& res) {
        for (const auto& arr: res) {
            for (const auto& val: arr) {
                std::cout << val << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    };

    res = so->combinationSum3(3, 7);
    print(res);

    res = so->combinationSum3(3, 9);
    print(res);
}
