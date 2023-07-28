#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
class Solution {
private:
    vector<vector<int>> result;
    void backtrack(int n, int k, vector<int>& com, int idx) {
        if (k == com.size()) {
            result.push_back(com);
            return;
        }
        for (int i = idx; i <= n; i ++) {
            com.push_back(i);
            backtrack(n, k, com, i+1);
            com.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> com;
        backtrack(n, k, com, 1);
        return result;
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
    vector<vector<int>> vv = so->combine(5, 3);
    print(vv);
}
