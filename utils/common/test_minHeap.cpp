#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

using std::vector;
class MinHeap {
private:
    vector<int> heap;
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }
    int parent(int i) { return (i-1)/2; }
public:
    MinHeap() {};
    void insert(int key) {
        heap.push_back(key);
        int index = heap.size()-1;
        while (index > 0 && heap[index] < heap[parent(index)]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        
        if (l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }

        if (r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            std::swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }

    int getMin() {
        if (!heap.empty()) {
            return heap[0];
        }
        return -1;
    }

    int extractMin() {
        if (heap.empty()) {
            return -1;
        } 
        
        if (heap.size() == 1) {
            int val = heap[0];
            heap.pop_back();
            return val;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return root;
    }

    bool isEmpty() { return heap.empty(); }
};

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    MinHeap *mp = new MinHeap();
    for (int i = 0; i < 10; i ++) {
        int val = dis(gen);
        std::cout << val << " ";
        mp->insert(val);
    }
    std::cout << "\n";

    while (!mp->isEmpty()) {
        std::cout << mp->getMin() << " ";
        mp->extractMin();
    }
    std::cout << "\n";
}
