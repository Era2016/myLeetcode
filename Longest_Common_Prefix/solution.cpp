#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int length = strs.size();
            if (length == 0) {
                return "";
            } 

            string commonStr = strs[0];
            int commonLen = strs[0].length();
            for (int i = 1; i < (int)strs.size(); ++ i) {
                for (int k = 0; ; ++ k) {
                    if (k >= commonLen || commonStr[k] != strs[i][k] || k >= (int)strs[i].length()) {
                        commonLen = k;
                        break;
                    }
                }
            }
            return commonStr.substr(0, commonLen);
        }

        string longestCommonPrefix_v2(vector<string> &strs) {  
            if (strs.empty())  
                return "";  
            for (int i = 0; i < (int)strs[0].length(); i++) {  
                for (int j = 1; j < (int)strs.size(); j++)  
                    if (i >= (int)strs[j].length() || strs[j][i] != strs[0][i])  
                        return strs[0].substr(0, i);  
            }  
            return strs[0];  
        }  
};

int main()
{
    Solution* so = new Solution();
    string str1 = "hello world";
    string str2 = "hello nothing";
    string str3 = "hel";
    vector<string> v;
    //v.push_back(str1);
    //v.push_back(str2);
    //v.push_back(str3);

    //string str = so->longestCommonPrefix_v2(v);
    string str = so->longestCommonPrefix(v);
    cout << str << endl;

    return 0;
}
