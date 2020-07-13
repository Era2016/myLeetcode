#include <iostream>
#include <vector>

using namespace std;;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }

private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int> >& subs) {
        subs.push_back(sub);
        for (int j = i; j < (int)nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<vector<int> > vv;
    Solution* so = new Solution();
    vv = so->subsets(v);

    for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
        for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
            cout << *it << "\t";
        }
        cout << endl;
    }
}
