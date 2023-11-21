/**
 * bfs
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::string;

class Solution {
private:
    bool isValid(string s) {
        int count = 0;
        for (const auto& c: s) {
            if (c == '(') {
                count ++;
            } else if(c == ')') {
                count --;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> us;
        vector<string> result;
        us.insert(s);
        while (true) {
            for (const auto& str: us) {
                if (isValid(str)) {
                    result.push_back(str);
                }
            }
            if (result.size() > 0) {
                return result;
            }
            unordered_set<string> tmp;
            for (const auto& str: us) {
                for (int i = 0; i < str.length(); i ++) {
                    if (i > 0 && str[i] == str[i-1]) {
                        continue;
                    }
                    if (str[i] == '(' || str[i] == ')') {
                        tmp.insert(str.substr(0, i)+str.substr(i+1, str.length()));
                    }
                }
            }
            us = tmp;
        }
    } 
};

int main() {
    Solution *so = new Solution();
    vector<string> result;

    auto print=[](vector<string>& v) {
        for (const auto& i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    };
    result = so->removeInvalidParentheses("()())()");
    print(result);

    result = so->removeInvalidParentheses("(a)())()");
    print(result);

    result = so->removeInvalidParentheses(")(");
    print(result);
}
