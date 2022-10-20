#include <vector>

class PrefixSum {
private:
    std::vector<int> sum;
public:
    PrefixSum(std::vector<int>& v);
    int query(int start, int end);
};
