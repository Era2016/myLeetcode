#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>);
void print(vector<vector<int>>);

class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<int>& v, vector<int>& used) {
        if (v.size() == nums.size()) {
            result.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (used[i]) continue;

            used[i] = true;
            v.push_back(nums[i]);
            //print(v); // 输出中间结果
            backtrack(nums, v, used);
            used[i] = false;
            v.pop_back();
            //print(v); // 输出中间结果
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<int> used(nums.size(), 0);
        backtrack(nums, v, used);
        return result;
    }
};

void print(vector<vector<int>> vv) {
    for (vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); it ++) {
        for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i ++) {
            cout << *i << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3};
    //vector<int> v = {0, 1};
    //vector<int> v = {1};

    vector<vector<int>> vv;
    Solution* so = new Solution();
    vv = so->permute(v);
    print(vv);
}
