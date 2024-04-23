#include <iostream>
#include <string>

using std::string;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long res = 0;
        for (auto c: columnTitle) {
            res = res*26 + c-'A'+1; 
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    string str;
    for (int i = 0; i < 26; i ++) {
        string str(1, i+'A'); 
        std::cout << str << "=====" << so->titleToNumber(str) << std::endl;
    } 

    str = "AA";
    std::cout << str << "=====" << so->titleToNumber(str) << std::endl;
}
