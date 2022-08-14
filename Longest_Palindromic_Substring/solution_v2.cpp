/**
 * 内存占用很大
 * 相比于直接返回回文字符串相差无几
 * 不确定在什么地方消耗内存
 * ??
 */

#include <iostream>
#include <string>
#include <cassert>

using std::string;

class Solution {
private:
    int lenPalindrome(string s, int* i, int* j) {
        while (*i >= 0 && *j < s.length() &&
                s[*i] == s[*j]) {
            (*i) --;
            (*j) ++;
        }
        return (*j)-(*i)-2+1;
        //return s.substr(i+1,j-1-i); 
    }
public:
    string longestPalindrome(string s) {
        int max = -1;
        int start, end;
        for (int i = 0; i < s.length(); i ++) {
            int t1 = i, t2 = i;
            int len1 = lenPalindrome(s, &t1, &t2);
            if (len1 > max) {
                max = len1;
                start = t1+1, end = t2-1;
                std::cout << "even len: " << max << " index: " << start << " string: " << s.substr(start, end-start+1) << std::endl;
            }

            int t3 = i, t4 = i+1;
            int len2 = lenPalindrome(s, &t3, &t4);
            if (len2 > max) {
                max = len2;
                start = t3+1, end = t4-1; 
                std::cout << "odd len: " << max << " index: " << start << " string: " << s.substr(start, end-start+1) << std::endl;
            }
        }

        return s.substr(start, end-start+1);
    }
};

int main () {
    Solution *so = new Solution();
    string origin, str;

    origin = "ababd";
    str = so->longestPalindrome(origin);
    std::cout << str << std::endl;
    //assert(so->longestPalindrome(origin) == "aba");

    origin = "cbbd";
    str = so->longestPalindrome(origin);
    std::cout << str << std::endl;
    
    
    origin = "d";
    str = so->longestPalindrome(origin);
    std::cout << str << std::endl;
}
