#include <iostream>

using std::string;
class Solution {
public:
    string reverseWords(string str) {
        std::reverse(str.begin(), str.end());
        string res;
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == ' ') {
                continue;
            }
            int j = i;
            while (j < str.length() && str[j] != ' ') {
                j ++;
            }
            
            std::reverse(str.begin()+i, str.begin()+j);
            res += str.substr(i, j-i) + " ";
            //std::cout << "sub:: " << res << std::endl;
            i = j;
        }

        //return res.substr(0, res.length()-1) ;
        res.erase(res.begin()+res.length()-1);
        return res;
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
