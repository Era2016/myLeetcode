#include <iostream>
#include <stack>

using std::stack;
using std::string;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        int i = 0;
        while(i < s.length()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                ss.push(s[i ++]);
            } else {
                if (ss.empty()) {
                    return false;
                }
                char c = ss.top(); ss.pop();
                if (s[i] == ')' && c == '(' || 
                        s[i] == ']' && c == '[' ||
                        s[i] == '}' && c == '{') {

                    i ++;
                } else {
                    return false;
                }
            }
        }
        //std::cout << ss.empty() << std::endl;
        return ss.empty();
    }
};

int main() {
    Solution *so = new Solution();
    std::cout << so->isValid("()") << std::endl;
    std::cout << so->isValid("[)") << std::endl;
}
