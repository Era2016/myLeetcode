#include "difference.h"

Difference::Difference(std::vector<int>& v) {
    diff.resize(v.size());
    diff[0] = v[0];
    for (int i = 1; i < v.size(); i ++) {
        diff[i] = v[i] - v[i-1];
    }
}

void Difference::increment(int i, int j, int val) {
    diff[i] += val;
    if (j+1 < diff.size())
        diff[j+1] -= val;
}

std::vector<int> Difference::result() {
    std::vector<int> res(diff.size());
    res[0] = diff[0];
    for (int i = 1; i < diff.size(); i ++) {
        res[i] = res[i-1] + diff[i-1];
    }
    return res;
}
