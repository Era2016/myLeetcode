#include <iostream>

using std::string;
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;
        while (start < end) {
            while (start < end && !isalnum(s[start])) {
                start ++;
            }

            while (start < end && !isalnum(s[end])) {
                end --;
            }

            if (start < end) {
                if (tolower(s[start]) != tolower(s[end])) {
                    return false;
                }
                start ++;
                end --;
            }
        }
        return true;
    }

};

int main() {
    Solution *so = new Solution();
    std::cout << so->isPalindrome("A man, a plan, a canal: Panama") << std::endl;

    char c1 = 'A';
    char c2 = 'a';
    char c3 = 'B';
    char c4 = c3+c2-c1;

    std::cout <<"c:" << c1 << "-" << c2 << "-" << c3 << "-" << c4 << std::endl;
    std::cout << c3+c2-c1 << std::endl; 
}
