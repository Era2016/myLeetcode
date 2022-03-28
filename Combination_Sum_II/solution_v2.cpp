/*
 * 与官方答案类似，无结果
 */
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print(vector<pair<int, int>>);
void print(vector<vector<int>>);
void print(vector<int>);

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<pair<int, int>> freq;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i ++) {
            if (freq.empty() || freq.back().first != candidates[i]) {
                freq.emplace_back(candidates[i], 1);
            } else {
                freq.back().second ++;
            }
        }

        print(freq);
        vector<int> v;
        vector<vector<int>> vv;
        dfs(freq, target, vv, v, 0);
        return vv;
    }

    void dfs(vector<pair<int, int>>& freq, int target, vector<vector<int>>& vv, vector<int>& v, int depth) {
        if (target == 0){
            vv.push_back(v);
            return;
        }
        if (depth == freq.size() || freq[depth].first > target) 
            return;

        dfs(freq, target, vv, v, depth+1);
        
        int most = min(target/freq[depth].first, freq[depth].second);
        for (int i = 1; i <= most; i ++) {
            v.push_back(freq[i].first);
            cout << "input stack: " << freq[i].first << " depth: " << depth<< endl;
            dfs(freq, target-i*freq[i].first, vv, v, depth+1);
        }

        for (int i = 1; i <= most; i ++) {
            cout << "output stack: " << v.back()<< " depth: " << depth <<endl;
            v.pop_back();
        }
    }
};

void print(vector<pair<int, int>> v) {
    for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it ++) {
        cout << (*it).first << " -> " << (*it).second << endl;
    }
    cout << endl;
}

void print(vector<vector<int>> vv) {
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
    vector<int> v = {5,2,3,1};
    int target = 8;
    
    //vector<int> v = {10,1,2,7,6,1,5};
    //int target = 8; 

    //vector<int> v = {2,5,2,1,2};
    //int target = 5;

    vector<vector<int>> vv;
    Solution* so = new Solution();
    vv = so->combinationSum2(v, target);
    print(vv);
}
