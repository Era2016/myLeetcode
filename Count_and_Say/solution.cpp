#include <iostream>
#include <string>

using std::string;
class Solution {
private:
    string transfer(string str_n) {
        string str;
        int len = str_n.length();
        int cnt = 1;
        for (int i = 0; i < len; i ++) {
            if (i < len-1 && str_n[i] == str_n[i+1]) {
                cnt ++;
            } else if (str_n[i] != str_n[i+1]) {
                str += std::to_string(cnt)+str_n[i];
                cnt = 1;
            } else {
                str += '1'+str_n[i];
            }
        }
        return str;
    }
public:
    string countAndSay(int n) {
        string str = std::to_string(1);
        for (int i = 2; i <= n; i ++) {
            str = transfer(str);
        }
        return str;
    }
};

int main() {
    Solution *so = new Solution();

    for (int i = 1; i <= 30; i ++) {
        std::cout << so->countAndSay(i) << std::endl;
    }
}
