#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum3(int k, int n) {
            vector<vector<int> > vv;
            vector<int> v;
            combinationSum3DFS(vv, v, k, n, 1, 1);
            return vv;
        }

        // 此处函数cur表示递归深度，并不能代表v中元素个数
        // 所以不能用cur与k的比值来判断是否需要写进vv二维数组中
        void combinationSum3DFS(vector<vector<int> >& vv, vector<int>& v, int k, int n, int cur, int start) {
            if (n < 0) {
                return ;
            //} else if (n == 0 && k == cur) { // k = 3 & cur = 0
            } else if (n == 0 && (int)v.size() == k) {
                //cout << "index : " << k<< "\t"<<"cur index : " << cur << endl;
                vv.push_back(v);
            } else {
                for (int i = start; i <= 9; ++ i) {
                    if (cur <= k) {
                        v.push_back(i);
                        combinationSum3DFS(vv, v, k, n - i, cur ++, i + 1);
                        cur --;
                        v.pop_back();
                    }
                } 
            }
        }
};

int main()
{
    Solution* so = new Solution();
    vector<vector<int> > vv;
    int k, n;
    cout << "please input k & n :" << endl;
    cin >> k;
    cin >> n;
    vv = so->combinationSum3(k, n);

    for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
        for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    return 0;
}
