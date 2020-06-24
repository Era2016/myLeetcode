#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int> >& matrix) {
            int n = matrix.size();
            for (int i = 0; i < n / 2; ++i) {
                for (int j = i; j < n - 1 - i; ++j) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[n - 1 - j][i];
                    matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                    matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                    matrix[j][n - 1 - i] = tmp;
                }
            }
        }
};

int main()
{
	Solution* so = new Solution();
	vector<vector<int> > matrix;

	vector<int> row;
	for (int i = 1; i <= 25; i ++) {
		row.push_back(i);
		if (i % 5 == 0) {
			matrix.push_back(row);
			row.clear();
		}
	}

	so->rotate(matrix);
	for (vector<vector<int> >::iterator iter = matrix.begin(); iter != matrix.end(); ++ iter) {
        for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++ it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}
