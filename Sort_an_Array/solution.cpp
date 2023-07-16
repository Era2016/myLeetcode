#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::swap;
using std::unordered_map;

class Solution {
private:
    int partition(vector<int>& nums, int start, int end) {
        int randIndex = rand()%(end-start+1)+start;
        swap(nums[end], nums[randIndex]);

        int small = start-1;
        for (int i = start; i < end; i ++) {
            if (nums[i] <= nums[end]) {
                small ++;
                swap(nums[small], nums[i]);
            }
        }

        small ++;
        swap(nums[small], nums[end]);
        return small;
    }

    // 重复数据过多，会影响排序效率
    void quickSort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int pivot = partition(nums, start, end);
            quickSort(nums, start, pivot-1);
            quickSort(nums, pivot+1, end);
        }
    }

    void mergeSort(vector<int>& nums, int start, int end, vector<int>& tmp) {
        if (start < end) {
            int mid = (end-start)/2 + start;
            mergeSort(nums, start, mid, tmp);
            mergeSort(nums, mid+1, end, tmp);
            merge(nums, start, mid, end, tmp);
        }
    }

    void merge(vector<int>& nums, int start, int mid, int end, vector<int>& tmp) {
        for (int i = start; i <= end; i ++) {
            tmp[i] = nums[i];
        }

        int i = start, j = mid+1;
        int index = start;
        while (i <= mid && j <= end) {
            if (tmp[i] < tmp[j]) {
                nums[index ++] = tmp[i ++];
            } else {
                nums[index ++] = tmp[j ++];
            }
        }
        while (i <= mid) {
            nums[index ++] = tmp[i ++];
        }
        while (j <= end) {
            nums[index ++] = tmp[j ++];
        }
    }

    void countingSort(vector<int>& nums) {
        unordered_map<int, int> counts;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        for (auto& val: nums) {
            counts[val] ++;
        }
        
        int index = 0;
        for (int i = minVal; i <= maxVal; i ++) {
            if (counts.find(i) != counts.end()) {
                while (counts[i] > 0) {
                    nums[index ++] = i;
                    counts[i] --;
                }
            } // endof if
        }// endof for
    }

    // Bucket sort function for each place value digit.
    void bucketSort(vector<int>& arr, int placeValue) {
        vector<vector<int>> buckets(10, vector<int>());
        // Store the respective number based on its digit.
        for (int& val: arr) {
            int digit = abs(val)/placeValue;
            digit = digit % 10;
            buckets[digit].push_back(val);
        }

        // Overwrite 'arr' in sorted order of current place digits.
        int index = 0;
        for (int digit = 0; digit < 10; ++ digit) {
            for (int& val: buckets[digit]) {
                arr[index ++] = val;
            }
        }
    }

    void radixSort(vector<int>& arr) {
        // Find the absolute maximum element to find max number of digits.
        int maxElement = arr[0];
        for (int& val: arr) {
            maxElement = std::max(abs(val), maxElement);
        }
        int maxDigits = 0;
        while (maxElement > 0) {
            maxDigits += 1;
            maxElement /= 10;
        }

        // Radix sort, least significant digit place to most significant.
        int placeValue = 1;
        for (int digit = 0; digit < maxDigits; ++ digit) {
            bucketSort(arr, placeValue);
            placeValue *= 10;
        }

        // Seperate out negatives and reverse them. 
        vector<int> negatives, positives;
        for (int& val: arr) {
            if (val < 0) negatives.push_back(val);
            else positives.push_back(val);
        }
        reverse(negatives.begin(), negatives.end());
        // Final 'arr' will be 'negative' elements, then 'positive' elements.
        std::merge(negatives.begin(), negatives.end(), positives.begin(), positives.end(), arr.begin());
    }

public:
    vector<int> sortArrayWithQuickSort(vector<int>& nums) {
        srand(time(nullptr));
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    vector<int> sortArrayWithMergeSort(vector<int>& nums) {
        vector<int> tmp(nums);
        mergeSort(nums, 0, nums.size()-1, tmp);
        return nums;
    }

    vector<int> sortArrayWithCountingSort(vector<int>& nums) {
        countingSort(nums);
        return nums;
    }

    vector<int> sortArrayWithRadixSort(vector<int>& nums) {
        radixSort(nums);
        return nums;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> v;
 
    auto print=[](vector<int>& nums) {
        for (const auto& v: nums) {
            std::cout << v << "\t";
        }
        std::cout << std::endl << std::endl;
    };

    v = {5,2,3,1};
    so->sortArrayWithQuickSort(v);
    so->sortArrayWithMergeSort(v);
    print(v);

    v = {5,1,1,2,0,0};
    so->sortArrayWithQuickSort(v);
    //so->sortArrayWithMergeSort(v);
    print(v);
    
    v = {2,2,2,2};
    so->sortArrayWithQuickSort(v);
    //so->sortArrayWithMergeSort(v);
    print(v);
}
