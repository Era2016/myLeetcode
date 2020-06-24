#include <iostream>
#include <vector>
using namespace std;

//int** threeSum(int* nums, int numsSize, int* returnSize); 
class Solution {
    public:
        vector<vector<int> > threeSum(vector<int>& nums) {
            vector<vector<int> > res; 
            int len = nums.size();
            if (len < 3) {
                return res;
            }

            sort(nums.begin(), nums.end());
            for (int i = 0; i < len; ++ i) {
                if (nums[i] > 0) {
                    break;
                }
                if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
                }
                int begin = i + 1;
                int end = len - 1;
                while(begin < end) {
                    int sum = nums[i] + nums[begin] + nums[end];
                    if (sum == 0) {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[begin]);
                        t.push_back(nums[end]);
                        res.push_back(t);
                        begin ++;
                        end --;
                        while (begin < end && nums[begin] == nums[begin-1]) {
                            begin ++;
                        }

                        while (begin < end && nums[end] == nums[end+1]) {
                            end --;
                        }

                    } else if (sum > 0) {
                        end --;
                    } else {
                        begin ++;
                    }
                }
                
            }
            return res;
        }
};

int main()
{
    vector<int> vv;
    /*for (int i = 0; i < 10; ++ i) {
        vv.push_back(100 - i);
    }*/
    vv.push_back(-1);
    vv.push_back(0);
    vv.push_back(1);

    vv.push_back(2);
    vv.push_back(3);
    

    vv.push_back(-2);
    vv.push_back(0);
    vv.push_back(4);

    sort(vv.begin(), vv.end());
    /*for (int i = 0; i < (int)vv.size(); ++ i) {
        cout << vv[i] << endl;
    }*/
    Solution* so = new Solution();
    vector<vector<int> > v;
    v = so->threeSum(vv);
    vector<vector<int> >::iterator iter = v.begin();
    for (; iter != v.end(); iter ++) {
        for (vector<int>::iterator it = iter->begin(); it != iter->end(); it ++) {
            cout << *it << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
