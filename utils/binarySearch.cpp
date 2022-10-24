#include <vector>
#include "binarySearch.h"

std::vector<int> BinarySearch::searchRange(int target) {
    int left = leftBound(target);
    int right = rightBound(target);
    return {left, right};
}

int BinarySearch::leftBound(int target) {

    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    if (left == nums.size()) return -1;
    return (nums[left] == target)? left: -1;
}

int BinarySearch::rightBound(int target) {

    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    if (left - 1 < 0) return -1;
    return (nums[left-1] == target)? left-1: -1;
}

