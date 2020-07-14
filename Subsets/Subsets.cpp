#include <iostream>
#include <vector>

using namespace std;
void print(vector<vector<int> >);

class Solution {
    public:
        vector<vector<int> > subsets(vector<int>& nums) {
            vector<vector<int> > vv;
            vector<int> v;
            vv.push_back(v);

            for(int i=0; i<(int)nums.size(); i ++) {
                for (vector<vector<int> >::iterator iter=vv.begin(); iter != vv.end(); iter ++) {
                    iter->push_back(nums[i]);
                }

                vector<int> tmpV(1, nums[i]);
                vv.push_back(tmpV);
            }

            return vv;
        }

		vector<vector<int> > subsets2(vector<int>& nums) {
			vector<vector<int> > subs;
			vector<int> sub;
			subs.push_back(sub);
			for (int num : nums) {
				int n = subs.size();
				cout << "current size: \t" << n << endl;
				for (int i = 0; i < n; i++) {
					subs.push_back(subs[i]); 
					subs.back().push_back(num);
				}
				cout << "current vector: " << endl;
			    print(subs);

			}
			return subs;
    } 
};

void print(vector<vector<int> > vv) {
    for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
        for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
            cout << *it << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<vector<int> > vv;
    Solution* so = new Solution();
    vv = so->subsets2(v);

	cout << "result: " << endl;
	print(vv);
    //for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
    //    for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
    //        cout << *it << "\t";
    //    }
    //    cout << endl;
    //}
}
