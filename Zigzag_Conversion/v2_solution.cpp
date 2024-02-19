#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows < 2)
			return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows -1)
                flag = - flag;
            i += flag;
        }
        string res;
        for (const string &row : rows)
            res += row;
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << so->convert("PAYPALISHIRING", 4) << std::endl;
    std::cout << so->convert("A", 1) << std::endl;
    std::cout << so->convert("AB", 1) << std::endl;
}
