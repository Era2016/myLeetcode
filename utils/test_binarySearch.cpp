#include <iostream>
#include <vector>
#include "binarySearch.h"

using std::vector;
int main() {
    BinarySearch *bs;
    vector<int> v;
    auto print = [](vector<int> v) { for(auto i: v) std::cout << i << "\t"; std::cout << std::endl << std::endl; };
    
    v = {5,7,7,8,8,10};
    bs = new BinarySearch(v);
    v = bs->searchRange(8);
    print(v);


    v = {5,7,7,8,8,10};
    bs = new BinarySearch(v);
    v = bs->searchRange(6);
    print(v);


    v = {};
    bs = new BinarySearch(v);
    v = bs->searchRange(0);
    print(v);
}
