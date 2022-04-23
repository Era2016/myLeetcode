#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print(vector<pair<int, int>>& v);
void print(vector<vector<int>>& v);

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<pair<int, int>> source;
        for (int i = 0; i < candidates.size(); i ++) {
            if (source.empty() || source.back().first != candidates[i]) {
                source.push_back(pair<int, int>(candidates[i], 1));
            } else {
                source.back().second ++;
            }
        }

        //print(source);

        vector<int> v;
        vector<vector<int>> vv;
        dfs(source, vv, v, target, 0);

        return vv;
    }

    void dfs(vector<pair<int, int>>& source, vector<vector<int>>& vv, 
            vector<int>& v, int target, int depth) {

        if (target == 0) {
            vv.push_back(v);
            return ;
        }

        if (depth == source.size() || target < 0) {
            return ;
        }

        
        dfs(source, vv, v, target, depth+1);

        int most = min(target/source[depth].first, source[depth].second);
        for (int i = 1; i <= most; i ++) {
            //cout << "input stack: " << source[depth].first << endl;
            v.push_back(source[depth].first);
            dfs(source, vv, v, target - i*source[depth].first, depth+1);
        }
        
        for (int i = 1; i <= most; i ++) {
            //cout << "output stack: " << v.back() << endl;
            v.pop_back();
        }
    }
};

void print(vector<pair<int, int>>& v) {
    for (vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); iter ++) {
        cout << (*iter).first << " -> " << (*iter).second << endl;
    }
    cout << endl;
}

void print(vector<vector<int>>& vv) {
    for (vector<vector<int>>::iterator iter = vv.begin(); iter != vv.end(); iter ++) {
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it ++) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    //vector<int> v =  {10,1,2,7,6,1,5};
    //int target = 8;

    vector<int> v = {2,5,2,1,2};
    int target = 5;

    Solution* so = new Solution();
    vector<vector<int>> vv = so->combinationSum2(v, target); 
    print(vv); 
}

