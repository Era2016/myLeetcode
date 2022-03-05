#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> m;
            for (int i = 0; i < nums.size(); i ++) {
                m[nums[i]] = i;
            }

            map<int, int>::iterator it;
            vector<int> ret;
            for (int i = 0; i < nums.size(); i ++) {
                it = m.find(target - nums[i]);
                if (it != m.end() && it->second != i) {
                    ret.push_back(i);
                    ret.push_back(it->second);
                    break;
                }
            }
            return ret;
        }

        vector<int> twoSum2(vector<int>& nums, int target) {
            unordered_map<int, int> m; // c++11
            unordered_map<int, int>::iterator it;

            for (int i = 0; i < nums.size(); i ++) {
                it = m.find(target - nums[i]);
                if (it != m.end()) return {it->second, i}; // c++11
                else m[nums[i]] = i;
            }
            return {};
        }
};

void print(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++) 
        cout << *it << "\t";
    cout << endl;
}

int main() {
    int arr[] = {2,7,11,15};
    int target = 9;
    
    //int arr[] = {3,2,4};
    //int target = 6;

    //int arr[] = {3,3};
    //int target = 6;
    
    Solution* so = new Solution();
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<int> r = so->twoSum2(nums, target); 
    print(r);
}
