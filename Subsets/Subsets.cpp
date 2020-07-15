#include <iostream>
#include <vector>

using namespace std;
void print(vector<vector<int> >);

class Solution {
    public:
        // 迭代法
		vector<vector<int> > subsets1(vector<int>& nums) {
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

		// bit 操作法
        // {1,2,3}
        // 0 000 {}
        // 1 001 {1}
        // 2 010 {2}
        // 3 011 {1,2}
        // 4 100 {3}
        // 5 101 {1,3}
        // 6 110 {2,3}
        // 7 111 {1,2,3}
		vector<vector<int> > subsets2(vector<int>& nums) {
			int n = nums.size(), p = 1 << n;
			vector<vector<int> > subs(p);
			for (int i = 0; i < p; i++) {
				for (int j = 0; j < n; j++) {
					if ((i >> j) & 1) {
						subs[i].push_back(nums[j]);
					}
				}
                cout << "current vector: " << endl;
				print(subs);
			}
			return subs;
		}

		// 递归法
        vector<vector<int> > subsets3(vector<int>& nums) {
            vector<vector<int> > vv;
            vector<int> v;
            subsets3(vv, v, nums, 0);

            return vv;
        }

    private:
        void subsets3(vector<vector<int> >& vv, vector<int>& v, vector<int>& nums, int start) {
            vv.push_back(v);
            for (int i = start; i < (int)nums.size(); i ++) {
                v.push_back(nums[i]); 
                subsets3(vv, v, nums, i+1);
                v.pop_back();
            } 
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

	cout << endl << "result: " << endl;
	print(vv);
    //for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
    //    for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
    //        cout << *it << "\t";
    //    }
    //    cout << endl;
    //}
}
