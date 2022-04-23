#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> vv;
        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, vv, v, 0);
        return vv;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& vv, vector<int>& v, int idx) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            vv.push_back(v);
            return;
        }

        for (int i = idx; i < candidates.size(); i ++) {
            if (i > idx && candidates[i-1] == candidates[i])
                continue;
            v.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], vv, v, i+1);
            v.pop_back();
        }
    }
};


void print(vector<vector<int>> vv) {
    cout << "output vector ..." << endl;
    for (vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); it ++) {
        for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i ++) {
            cout << *i << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void print(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++)
        cout << *it << "\t";
    cout << endl;
}

int main() {
    //vector<int> v = {5,2,3,1};
    //int target = 8;
    
    vector<int> v = {10,1,2,7,6,1,5};
    int target = 8; 

    //vector<int> v = {2,5,2,1,2};
    //int target = 5;

    vector<vector<int>> vv;
    Solution* so = new Solution();
    vv = so->combinationSum2(v, target);
    print(vv);
}
