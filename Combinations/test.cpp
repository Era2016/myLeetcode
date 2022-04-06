#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& );
void print(vector<vector<int>>& );

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> vv;

        dfs(1, vv, v, n, k, 0);
        return vv;
    }
    
    void dfs(int cur, vector<vector<int>>& vv, vector<int>& v, int n, int k, int idx) {
        // 剪枝：v 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 v
        if (v.size() + n - cur + 1 < k) return;

        // 两个if条件判断有先后顺序，如果颠倒，会导致部分符合条件的情况没有压入栈内
        if (idx == k) {
            vv.push_back(v);
            return;
        }

        if (cur == n + 1) return;

        // 考虑选择当前位置
        v.push_back(cur);
        dfs(cur+1, vv, v, n, k, idx+1);
        v.pop_back();

        // 考虑不选择当前位置
        dfs(cur+1, vv, v, n, k, idx);
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

void print(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++) 
        cout << *it << "\t";
    cout << endl;
}

int main() {
    Solution* so = new Solution();
    vector<vector<int>> vv = so->combine(5, 3);
    print(vv);
}
