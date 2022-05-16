#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void print(vector<vector<int>>& vv);
void print(vector<int>& v);

class Solution {
private:
    int total;
    int n, k;
public:
    string getPermutation(int n, int k) {
        //this->used.resize(n, 0); 
        this->total = getNCount(n);
        this->n = n;
        this->k = k;

        vector<int> ret;
        vector<int> used (n, 0);

        dfs(ret, used, 0);
        //print(ret);
        
        stringstream ss;
        copy(ret.begin(), ret.end(), ostream_iterator<int>(ss, ""));
        return ss.str();
    }

    void dfs(vector<int>& ret, vector<int>& used, int depth) {
        if (depth == n) {
            return ;
        }

        // 计算还未确定的数字的全排列的个数，第 1 次进入的时候是 n - 1
        int left = getNCount(n - depth - 1); 

        for (int i = 1; i <= n; i ++) {

            if (used[i-1]) continue;

            if (k > left) {
                k -= left;
                continue;
            }

            used[i-1] = 1;
            ret.push_back(i);
            dfs(ret, used, depth + 1);
            // 注意 1：不可以回溯（重置变量），算法设计是「一下子来到叶子结点」，没有回头的过程
            // 注意 2：这里要加 return，后面的数没有必要遍历去尝试了
            //v.pop_back();
            //used[i-1] = 0;
            return;
        }
    }

    int getNCount(int n) {
        int ret = 1;
        while (n >= 1) {
            ret *= n --;
        }
        return ret;
    }
};
void print(vector<vector<int>>& vv) {
    for (vector<vector<int>>::iterator iter = vv.begin(); iter != vv.end(); iter ++) {
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it ++) {
            cout << *it << "\t";
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

int main () {
    Solution* so = new Solution();
    //so->getPermutation(3, 2);
    //so->getPermutation(3, 6);
    string str = so->getPermutation(4, 1);
    cout << "ret: " << str << endl;
}
