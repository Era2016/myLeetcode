#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
                return b < a[0];
                });
        if (row == matrix.begin()) {
            return false;
        }
        --row;
        return binary_search(row->begin(), row->end(), target);
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

