#include "prefixsum.h"

PrefixSum::PrefixSum(std::vector<int>& v) {
    sum.resize(v.size()+1);
    for (int i = 1; i < v.size(); i ++) {
        sum[i] = sum[i-1] + v[i-1]; 
    }
}

int PrefixSum::query(int start, int end) {
    return sum[end+1] - sum[start];
}
