#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "" && haystack == "") {
            return 0;
        }
        int i = 0;
        for (; i < (int)haystack.length() - (int)needle.length() + 1; ++ i) {
            int j = 0;
            while (j < (int)needle.length() && j < (int)haystack.length() && needle[j] == haystack[i+j]) {
                j ++;
            }
            if (j == (int) needle.length()) {
                return i; 
            }
        } 
        return -1;
    }

    int strStr_v2(string haystack, string needle) {
        if( !needle.size() ) 
            return 0;
        if( !haystack.size() ) 
            return -1;
        
        int size = haystack.size() - needle.size() + 1;
        int n = 0;
        bool found;
        
        while(n < size) {
            if(haystack[n] == needle[0]) {
                if(needle.size() == 1)
                    found = true;
                for(int j = 1;j < needle.size(); j ++){
                    if(haystack[n+j] == needle[j])
                        found = true;
                    else{
                        found = false;
                        break;
                    }
                }
                if(found)
                    return n;
            }
            n ++;
        }
        if (found) 
            return n;
        else
            return -1;
  }
};

int main()
{
    Solution* so = new Solution();
    int n = so->strStr("aaaaaa", "bba");
    cout << n << endl;
    return 0;
}
