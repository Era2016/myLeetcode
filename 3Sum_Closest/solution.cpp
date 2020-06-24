#include<iostream>
#include<vector>
#include<map>
//#include<stdlib.h>

using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            map<int, vector<int> > mm;
            //vector<int> v;
            for (int i = 0; i < (int)nums.size() - 1; ++ i) {
                for (int j = i + 1; j < (int)nums.size(); ++ j) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    mm.insert(pair<int, vector<int> >(nums[i]+nums[j], v));
                }
            }

            int abs_min = 25535;
            int cur_sum = 0;
            int result = 0;
            map<int, vector<int> >::iterator iter = mm.begin();
            for (; iter != mm.end(); ++ iter) {
                /*vector<int> v = iter->second;
                for (vector<int>::iterator i = v.begin(); i != v.end(); ++ i) {
                    cout << "index : " << *i << "\t";
                }
                cout << endl  << "sum : " << iter->first << endl << endl;*/
                int start = iter->second.at(0);
                int end = iter->second.at(1);
                //int index = iter->first;
                //cout << start << "\t" << end << "\t" << index << endl;
                for (int j = 0; j < (int)nums.size(); ++ j) {
                    if (j == start || j == end) {
                        continue;
                    }
                    cur_sum = nums[j] + iter->first;
                    int abs_result = abs(cur_sum - target);
                    //cout << temp << "\t" << abs_min << endl;
                    if (abs_min > abs_result) {
                        abs_min = abs_result;
                        result = cur_sum;
                    }
                }
            }

            return result;
        }

        int threeSumClosest_v2(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int n = (int) nums.size();
            int res = nums[0] + nums[1] + nums[2];
            for (int i = 0; i < n; ++i) {
                int j = i + 1;
                int k = n - 1;
                while (j < k) {
                    int cur = nums[i] + nums[j] + nums[k];
                    if (abs(target - cur) < abs(target - res))
                        res = cur;
                    if (cur < target)
                        ++j;
                    else
                        --k;
                }
            }
            return res;
        }
};

int main()
{
    Solution* so = new Solution();
    vector<int> v;
    /*v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-4);*/

    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    int result = so->threeSumClosest_v2(v, 1);
    cout << "result :: "<< result << endl;
    return 1;
}
