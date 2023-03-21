#include <iostream>
#include <vector>

using std::vector;

class Solution {
private:
    vector<int> index;
    vector<int> result;
    vector<int> tmp;
    vector<int> tmpIndex;
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right-left)/2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left, j = mid + 1;
        int p = left;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[p] = nums[i];
                tmpIndex[p] = index[i];
                result[index[i] ] += j - mid - 1; 
                p ++, i ++;
            } else {
                tmp[p] = nums[j];
                tmpIndex[p] = index[j];
                p ++, j ++;
            }
        }

        while (i <= mid) {
            tmp[p] = nums[i];
            tmpIndex[p] = index[i];
            result[index[i] ] += j - mid - 1;
            p ++, i ++;
        }

        while (j <= right) {
            tmp[p] = nums[j];
            tmpIndex[p] = index[j];
            p ++, j ++;
        }

        for (int i = left; i <= right; i ++) {
            nums[i] = tmp[i];
            index[i] = tmpIndex[i];
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int length = nums.size();
        this->index.resize(length);
        this->tmp.resize(length);
        this->tmpIndex.resize(length);
        this->result.resize(length);
        for (int i = 0; i < length; i ++) {
            index[i] = i;
        }

        mergeSort(nums, 0, length-1);
        return this->result;
    }
    void clear() {
        this->index.clear();
        this->tmp.clear();
        this->tmpIndex.clear();
        this->result.clear();
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

    v = {5,2,6,1};
    ret = so->countSmaller(v);
    print(ret);
    so->clear();

    v = {-1};
    ret = so->countSmaller(v);
    print(ret);
    so->clear();

    v = {-1,-1};
    ret = so->countSmaller(v);
    print(ret);
    so->clear();

    v = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    ret = so->countSmaller(v);
    // [10,27,10,35,12,22,28,8,19,2,12,2,9,6,12,5,17,9,19,12,14,6,12,5,12,3,0,10,0,7,8,4,0,0,4,3,2,0,1,0]
    print(ret);
    so->clear();
}
