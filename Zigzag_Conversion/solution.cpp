#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        vector<vector<char>> vv(numRows, vector<char>(len, '#'));       
        int cursor = 0;
        int i = -2, j = 1;
        while (cursor < len) {
            for (i=i+2, j=j-1; i < numRows && cursor < len; i ++) {
                vv[i][j] = s[cursor ++];
            }
            if (i < numRows) {
                break;
            }

            i = i>=2? i-2: i-1; // 避免负数
            for (j=j+1; i >= 0 && cursor < len; i --) {
                vv[i][j ++] = s[cursor ++];
            }
            if (i >= 0) {
                break;
            }
        }

        //print(vv);
        string str;
        str.reserve(len);
        for (int i = 0; i < numRows; i ++) {
            for (int j = 0; j < len; j ++) {
                if (vv[i][j] != '#') {
                    //std::cout << vv[i][j] << "\n";
                    str += vv[i][j];
                }
            }
        }
        //std::cout << str << "\n";
        return str;
    }

    void print(vector<vector<char>>& vv) {
        for (auto v: vv) {
            for (auto val: v) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << so->convert("PAYPALISHIRING", 4) << std::endl;
    std::cout << so->convert("A", 1) << std::endl;
    std::cout << so->convert("AB", 1) << std::endl;
}
