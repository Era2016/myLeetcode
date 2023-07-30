
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& candidates, int target, vector<int>& combine, int idx) {
        if (target == 0) {
            result.push_back(combine);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); i ++) {
            combine.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], combine, i);
            combine.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        vector<int> combine;
        // 排序后，可以进一步剪枝，减少复杂度
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, combine, 0);
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> subset;
    vector<vector<int>> result;

    auto print=[](vector<vector<int>>& result) {
        for (const auto& arr: result) {
            for (const auto& v: arr) {
                std::cout << v << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    };

    subset = {2,3,6,7};
    result = so->combinationSum(subset, 7);
    print(result);

    subset = {2,3,5}; 
    result = so->combinationSum(subset, 8);
    print(result);
}
