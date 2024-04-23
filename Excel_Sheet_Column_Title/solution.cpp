#include <iostream>
#include <cassert>

using std::string;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str;
        while (columnNumber > 0) {
            columnNumber --;
            str.insert(str.begin(), columnNumber%26+'A');
            columnNumber /= 26;
        }
        return str;
    }
    
    string convertToTitle_v2(int columnNumber) {
        string str;
        while (columnNumber > 0) {
            int n = (columnNumber-1)%26+1;
            str.insert(str.begin(), n-1+'A');
            columnNumber = (columnNumber-n)/26;
        }
        return str;
    }
};

int main() {
    Solution *so = new Solution();
    for (int i = 1; i < 26*3; i ++) {
        assert(so->convertToTitle(i) == so->convertToTitle_v2(i));
        std::cout << so->convertToTitle(i) << "-----" << so->convertToTitle_v2(i) << std::endl;
    }
    std::cout << so->convertToTitle(701) << std::endl;
    std::cout << so->convertToTitle_v2(701) << std::endl;
}
