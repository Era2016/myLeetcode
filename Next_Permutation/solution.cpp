#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int length = nums.size();
            bool find = false;
            int index;
            //cout << length << endl;
            //print(nums);
            for (index = length - 1; index > 0; -- index) {
                if (nums[index-1] < nums[index]) {
                    find = true;
                    //cout << "find" << endl;
                    break;
                }
            }
            if (!find) {
                reverse(nums.begin(), nums.end());
                print(nums);
                return;
            } else {
                replace(nums, index, length);
                print(nums);
                return;
            }
        }            

        void replace(vector<int>& v, int target, int length) {
            int temp = v[target-1];
            int index = -1;
            //partial_sort(v.begin()+target-1, v.end(), v.end(), less<int>()); 
            for (int i = length - 1; i > target - 1; -- i) {
                if (v[i] > temp) {
                    swap(v[target-1], v[i]);
                    break;
                }
            }   
            //swap(v[target-1], v[index]);
            // 堆排序
            //partial_sort(v.begin()+target, v.end(), v.end(), less<int>());
            // 快排+插入排序
            sort(v.begin()+target, v.end());
        }

        void print(vector<int> v) {
            for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++ iter) {
                cout << *iter;
            }
            cout << endl;
        }

        void nextPermutation_v2(vector<int>& nums) {
            int k = -1;
            
            // Find the largest index k such that nums[k] < nums[k + 1].
            for (int i = nums.size() - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    k = i;
                    break;
                }
            }
            // the permutation is sorted in descending order
            if (k == -1) {
                reverse(nums.begin(), nums.end());
                return;
            }
            
            // Find the largest index l greater than k such that nums[k] < nums[l].
            int l = -1;
            for (int i = nums.size() - 1; i > k; i--) {
                if (nums[i] > nums[k]) {
                    l = i;
                    break;
                } 
            } 
            swap(nums[k], nums[l]);
            // reverse(nums.begin() + k + 1, nums.end());
            sort(nums.begin() + k + 1, nums.end());
        }
};


int main()
{
    Solution* so = new Solution();
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1); 

    //so->nextPermutation(v);   
    so->nextPermutation_v2(v);
    so->print(v);
    return 0;
}
