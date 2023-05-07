#include <iostream>

using std::string;
class Solution {
private:
    string reverse(string s) {
        for (int i = 0, j = s.length()-1; i < j; i ++, j--) {
            std::swap(s[i], s[j]);
        }
        return s;
    }
public:
    string reverseWords(string s) {
        string str = reverse(s);
        string res;
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == ' ') {
                continue;
            }
            int j = i;
            while (j < str.length() && str[j] != ' ') {
                j ++;
            }
            
            string sub = str.substr(i, j-i);
            //std::cout << "sub:: " << sub << std::endl; 
            res += reverse(sub)+" ";
            i = j;
        }

        return res.substr(0, res.length()-1) ;
    }
};

int main() {
    Solution *so = new Solution();
    string str;

    str = "the sky is blue";
    std::cout << so->reverseWords(str) << std::endl;

    str = "  hello world  "; 
    std::cout << so->reverseWords(str) << std::endl;

    str = "a good   example"; 
    std::cout << so->reverseWords(str) << std::endl;
}
