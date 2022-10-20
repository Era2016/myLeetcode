#include <vector>

class Difference {
private:
    std::vector<int> diff;
public:
    Difference(std::vector<int> &v);
    void increment(int start, int end, int val);
    std::vector<int> result();
};
