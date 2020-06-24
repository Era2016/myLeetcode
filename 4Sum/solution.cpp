#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int>& nums, int target) {
            vector<vector<int> > vv;
            sort(nums.begin(), nums.end());
            int length = (int)nums.size();

            for (int i = 0; i < length - 3; i ++) {
                //cout << "hello" << endl;
                if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
                }
                for (int j = i + 1; j < length - 2; ++ j) {
                    //cout << "world" << endl;
                    if (j > i + 1 && nums[j] == nums[j-1]) {
                        continue;
                    }
                    int start = j + 1;
                    int end = length - 1;
                    //int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    while (start < end) {
                        int sum = nums[i] + nums[j] + nums[start] + nums[end];
                        //cout << i << "\t"<< j<<"\t" <<start<< "\t" << end << endl;
                        if (sum == target) {
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[start]);
                            v.push_back(nums[end]);
                            vv.push_back(v);
                            //cout << i << "\t" << j << "\t" << start << "\t" << end << endl; 
                            start ++;
                            end --;
                            while (start < end && nums[start] == nums[start-1]) {
                                start ++;
                            }
                            while (end > start && nums[end] == nums[end+1]) {
                                end --;
                            }
                        } else if (sum < target) {
                            start ++;
                        } else {
                            end --;
                        }
                    }// end of while 
                }// end of j while
            }// end of i while
            return vv;
        }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(-1);
    v.push_back(0);
    v.push_back(-2);
    v.push_back(2);
    Solution* so = new Solution();
    vector<vector<int> > vv;
    vv = so->fourSum(v, 0);
    for (vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {

        vector<int> v = *iter;
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++ it) {
            cout << (*it) << "\t";
        }
        cout << endl;
    }

    return 0;
}
