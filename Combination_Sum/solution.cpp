#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            vector<vector<int> > res;
            vector<int> out;

            sort(candidates.begin(), candidates.end());
            combinationSumDFS(candidates, target, 0, out, res);
            return res;
        }

        void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int> >& res) {
            if (target < 0) 
                return ;
            else if (target == 0) {
                res.push_back(out);
            } else {
                for (int i = start; i < (int)candidates.size(); ++ i) {
                    out.push_back(candidates[i]);
                    combinationSumDFS(candidates, target - candidates[i], i, out, res);
                    out.pop_back();
                }
            }
        }
};

int main()
{
    Solution* so = new Solution();
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    vector<vector<int> >vv = so->combinationSum(v, 7);
    for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
        for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    return 0;
}
