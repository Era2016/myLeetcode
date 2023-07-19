#include <iostream>
#include <vector>
#include "maxHeap.h"

MaxHeap::MaxHeap(std::vector<int>& nums) { buildMaxHeap(nums); }
int MaxHeap::left(int i) { return (i << 1) + 1; }
int MaxHeap::right(int i) { return (i << 1) + 2; }
void MaxHeap::maxHeapify(int i) {
    int largest = i, l = left(i), r = right(i);
    if (l < heapSize && nums[l] > nums[largest]) largest = l;
    if (r < heapSize && nums[r] > nums[largest]) largest = r;
    if (largest != i) {
        std::swap(nums[i], nums[largest]);
        maxHeapify(largest);
    }
}
void MaxHeap::buildMaxHeap(std::vector<int>& nums) {
    this->nums = nums;
    this->heapSize = nums.size();
    for (int i = (heapSize >> 1)-1; i >= 0; i --) {
        maxHeapify(i);
    }
}
int MaxHeap::findKthLargest(int k) {
    std::vector<int> bak(nums);
    for (int i = 0; i < k - 1; i ++) {
        std::swap(nums[0], nums[--heapSize]);
        maxHeapify(0);
    }
    int res = nums[0];
    buildMaxHeap(bak);
    return res; 
}
