#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int> > vv;
            vector<int> v;
            sort(candidates.begin(), candidates.end());
            combinationSum2DFS(candidates, target, 0, vv, v);
            return vv;
        }

        void combinationSum2DFS(vector<int>& candidates, int target, int start, vector<vector<int> >& vv, vector<int>& v) {
            if (target < 0) {
                return ;
            } else if (target == 0) {
                vv.push_back(v);
            } else {
                for (int i = start; i < (int)candidates.size(); ++ i) {
                    if (i > start && candidates[i] == candidates[i-1]) {
                        continue;
                    } else {
                        v.push_back(candidates[i]);
                        combinationSum2DFS(candidates, target - candidates[i], i + 1, vv, v);
                        v.pop_back();
                    }
                }
            }  
        }
};

int main()
{
    Solution* so = new Solution();
    vector<int> v;
    v.push_back(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(6);
    v.push_back(1);
    v.push_back(5);
    vector<vector<int> > vv = so->combinationSum2(v, 8);

    for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
        for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    return 0;
}
