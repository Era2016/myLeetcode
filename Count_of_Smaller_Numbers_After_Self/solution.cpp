#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;
class Solution {
private:
    vector<int> ret;
    vector<int> tmp;
    vector<int> index;
    vector<int> tmpIndex;
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right); 
        
        merge(nums, left, mid, right);
        return;
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left;
        int j = mid+1;
        int ii = 0;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[ii] = nums[i];
                tmpIndex[ii] = index[i];
                ret[index[i] ] += j - mid - 1;
                ii ++, i ++;
            } else {
                tmp[ii] = nums[j];
                tmpIndex[ii] = index[j];
                ii ++, j ++;
            }
        }

        while (i <= mid) {
            tmp[ii] = nums[i];
            tmpIndex[ii] = index[i];
            ret[index[i] ] += j - mid - 1;
            ii ++, i ++;
        }

        while (j <= right) {
            tmp[ii] = nums[j];
            tmpIndex[ii] = index[j];
            ii ++, j ++;
        }
        
        for (int p=left, k=0; p <= right; p++, k++) {
            nums[p] = tmp[k];
            index[p] = tmpIndex[k];
        }
        return;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int numsSize = nums.size();
        ret.resize(numsSize);
        tmp.resize(numsSize);
        index.resize(numsSize);
        tmpIndex.resize(numsSize);
        for (int i = 0; i < nums.size(); i ++) {
            index[i] = i;
        }

        mergeSort(nums, 0, nums.size()-1);
        return ret;
    }
    
    void clear() {
        ret.clear();
        tmp.clear();
        index.clear();
        tmpIndex.clear();
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
    vector<int> ret;
    auto print = [](vector<int> ve) {
        for (auto v: ve) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    };

    //v = {5,2,6,1};
    //ret = so->countSmaller(v);
    //print(ret);
    //so->clear();

    //v = {-1};
    //ret = so->countSmaller(v);
    //print(ret);
    //so->clear();

    //v = {-1,-1};
    //ret = so->countSmaller(v);
    //print(ret);
    //so->clear();

    v = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    ret = so->countSmaller(v);
    // [10,27,10,35,12,22,28,8,19,2,12,2,9,6,12,5,17,9,19,12,14,6,12,5,12,3,0,10,0,7,8,4,0,0,4,3,2,0,1,0]
    print(ret);
    so->clear();
}
