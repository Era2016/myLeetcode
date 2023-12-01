#include <iostream>
#include "maxHeap.h"

using std::vector;
int main() {
    int maxSize = 10;
    vector<int> v = {9,1,3,2,7,5,6,0,4,8};
    MaxHeap *mh = new MaxHeap(v);
    std::cout << "size: " << v.size() << std::endl;
    for (int i = 1; i <= maxSize; i ++) {
        std::cout << mh->findKthLargest(i) << std::endl;
    }
}
