#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print(vector<vector<int>>& vv);
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int count = matrix.size();
        for (int i = 0; i < count; i ++) {
            for (int j = i; j < count; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //print(matrix);

        for (int i = 0; i < count; i ++) {
            for (int j = 0; j < count/2; j ++) {
                swap(matrix[i][j], matrix[i][count-j-1]);
            }
        }
        //print(matrix);
    }
};

void print(vector<vector<int>>& vv) {
    for (auto v: vv) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl;
}

vector<vector<int>> genVectors(int m, int n) {
    vector<vector<int>> vv(m, vector<int>(n));
    for (auto& v: vv) {
        //generate(v.begin(), v.end(), [i=0]() mutable{return i++;});
        generate(v.begin(), v.end(), []() {return rand()%10; });
    }
    return vv;
}

int main() {
    Solution* so = new Solution();

    // 3*3
    auto vv = genVectors(3,3);
    print(vv);

    so->rotate(vv);
    print(vv);


    // 4*4
    vv = genVectors(4,4);
    print(vv);

    so->rotate(vv);
    print(vv);
}
