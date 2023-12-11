#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        // x -> (x/n, x%n)
        int left = 0, right = m*n-1;
        while (left <= right) {
            int mid = (right-left)/2 + left;
            int val = matrix[mid/n][mid%n];
            if (target > val) {
                left = mid + 1;
            } else if (target < val) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int>> matrix;

    matrix = {
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };
    cout << so->searchMatrix(matrix, 3) << endl;
    cout << so->searchMatrix(matrix, 13) << endl;
}
