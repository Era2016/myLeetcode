#include <iostream>
#include <vector>
#include <queue>        // priority_queue
#include <set>          // multiset
#include <algorithm>    // nth_element + partial_sort

using namespace std;

class Solution {
public:
    int findKthLargest1(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>() );
        return nums[k-1];
    }

    int findKthLargest2(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin()+k, nums.end(), greater<int>() );
        return nums[k-1];
    }

    // with priority queue
    int findKthLargest3(vector<int>& nums, int k) {
        // min-heap
		priority_queue<int, vector<int>, greater<int> > pq;
		for (int i = 0; i < (int)nums.size(); i ++) {
			pq.push(nums[i]);
			if ((int)pq.size() == k+1) {
				pq.pop();
			}
		}
        
        // max-heap
        /*priority_queue<int> pq (nums.begin(), nums.end());
        for (int i = 0; i < k-1; i ++) {
            pq.pop(); 
        }*/

        return pq.top();
    }

    // with multiset
    int findKthLargest4(vector<int>& nums, int k) {
        // min-heap
        /*multiset<int> mset;
        for (int num : nums) {
            mset.insert(num);
            if ((int)mset.size() == k+1) {
                mset.erase(mset.begin());
            }
        }*/

        // max-heap
        multiset<int, greater<int> > mset(nums.begin(), nums.end());
        for (int i = 0; i < k-1; i ++) {
            mset.erase(mset.begin());
        }

        return *mset.begin();
    }

    // binary + quick.partition
    int findKthLargest5(vector<int>& nums, int k) {
        int start = 0;
        int end = (int) nums.size() - 1;
        int index = -1;
        k = (int) nums.size() - k;
        random_shuffle(nums.begin(), nums.end());
        while (start <= end) {
            index = partition(nums, start, end);
            if (index == k) {
                break;
            } else if (index < k) {
                start = index + 1;
            } else {
                end = index - 1;
            }
        }
        return nums[index];
    }

    int partition(vector<int>& v, int start, int end) {
        int index = start - 1;
        for (int i = start; i < end; i ++) {
            if (v[i] < v[end]) {
                if (i != index) {
                    index ++;
                    swap(v[i], v[index]);
                }
            }
        }
        index ++;
        swap(v[index], v[end]);
        return index;
    }
    
    void quickSort(vector<int>& v, int start, int end) {
        if (start < end) {
            int index = partition(v, start, end);
            quickSort(v, start, index-1);
            quickSort(v, index+1, end);
        }
    }
    
    // heap-sort
    //void findKthLargest6(vector<int>& nums, int k) {
    
    //}

};

int main() {
    Solution* so = new Solution();
    int val = 0;

    vector<int> v = {30,40,10,70,50,20,60};
    //so->quickSort(v, 0, v.size()-1);
    //for (int i = 0; i < (int)v.size(); i ++) {
    //    cout << v[i] << endl;
    //}
    for (int i = 1; i <= (int)v.size(); i ++) {
        val = so->findKthLargest5(v, i);
        cout << "result: " << val << endl;
    }
        

    //val = so->findKthLargest5(v, 7);
    //cout << "result: " << val << endl;
}
