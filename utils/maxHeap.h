class MaxHeap {
private:
    int heapSize;
    std::vector<int> nums;
    int left(int i);
    int right(int i);
    void maxHeapify(int i);
    void buildMaxHeap(std::vector<int>& nums);
public:
    MaxHeap(std::vector<int>& nums);
    int findKthLargest(int k);
};
