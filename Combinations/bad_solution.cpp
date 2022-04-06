#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> vv;
        vector<int> used(n, 0);
        dfs(n, k, vv, v, 0, used);
        return vv;
    }

    // 无法去重：该算法最终产生的结果是有序的，不符合无序/重复要求
    void dfs(int index, int k, vector<vector<int>>& vv, vector<int>& v, int depth, vector<int>& used) {
        if (depth == k) {
            vv.push_back(v);
            return;
        }

        for (int i = 0; i < index; i ++) {
            if (used[i]) continue;
            used[i] = true;
            //cout << "input stack: " << i << endl;
            v.push_back(i+1);
            dfs(index, k, vv, v, depth+1, used);
            //cout << "output stack: " << v.back() << endl;
            v.pop_back();
            used[i] = false;
        }
    }
};

void print(vector<vector<int>>& vv) {
    for (vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); it ++) {
        for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i ++) {
            cout << *i << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution* so = new Solution();
    vector<vector<int>> vv = so->combine(4, 3);
    print(vv);
}
