#include <vector>

class BinarySearch {
private:
    std::vector<int> nums;
    int leftBound(int target);
    int rightBound(int target);
public:
    BinarySearch(std::vector<int> v): nums(v) {};
    std::vector<int> searchRange(int target);
};
