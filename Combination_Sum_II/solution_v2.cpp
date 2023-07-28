#include <iostream>
#include <vector>

using std::vector;
class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& candidates, vector<int>& candi, int target, int idx) {
        if (target == 0) {
            result.push_back(candi);
            return;
        } else if (target < 0) {
            return;
        } else {
            for (int i = idx; i < candidates.size(); i ++) {
                if (i != idx && candidates[i] == candidates[i-1]) continue;
                candi.push_back(candidates[i]);
                backtrack(candidates, candi, target-candidates[i], i+1);
                candi.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        vector<int> candi;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, candi, target, 0);
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> candidates;
    vector<vector<int>> result;

    auto print=[](vector<vector<int>>& result) {
        for (const auto& arr: result) {
            for (const auto& val: arr) {
                std::cout << val << "\t";
            }
            std::cout << std::endl;
        }
    };
    candidates = {10,1,2,7,6,1,5};
    result = so->combinationSum2(candidates, 8);
    print(result);

    candidates = {2,5,2,1,2}; 
    result = so->combinationSum2(candidates, 5);
    print(result);
}
