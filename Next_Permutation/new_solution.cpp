#include <iostream>
#include <vector>

using namespace std;
void print(vector<int>);

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 遍历数组，找到从后算递增的第一个数组下标
        // 选择该下标后数组中刚刚大于该数组下标值，交换元素
        // 交换后，将后面数组按升序排列
        int length = nums.size();
        int index = length - 1;
        for (int i = length - 1; i >= 0; i --) {
            if (i >= 1 && nums[i] > nums[i-1]) {
                index = i - 1;
                break;
            }
        }

        int minNums = INT_MIN, minIndex = index;
        for (int i = index + 1; i < length; i ++) {
            if (nums[i] > nums[index]) {
                minNums = min(minNums, nums[i]);
                minIndex = i;
            }
        } 

        //cout << "index: " << index << "\t minIndex: " << minIndex << endl;
        swap(nums[index], nums[minIndex]);
        if (index == length - 1) { // 数组已是倒叙排列，需转换成正序输出
            sort(nums.begin(), nums.end());
        } else {
            sort(nums.begin()+index+1, nums.end());
        }
    }
};

void print(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;
}

int main() {
    //vector<int> v = {1,2,3,4,5,6}; // 123465
    //vector<int> v = {1,2,4,6,5,3}; // 125346
    //vector<int> v = {1}; // 
    vector<int> v = {3,2,1}; // 321
    Solution* so = new Solution();
    print(v);
    so->nextPermutation(v);
    print(v);
}
