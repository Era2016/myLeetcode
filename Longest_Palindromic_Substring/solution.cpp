#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = (int)s.length();
        if (length == 1) {
            return s.substr(0); 
        }
        if (length == 2) {
            return (s[1] == s[0]) ? s : s.substr(0, 1);
        }

        int max = 0;
        int index = 0;
        bool is_odd = true;
        for (int i = 1; i < length; ++ i) {
            int cur_odd = 1;
            int cur_even = 0;
            for (int j = i - 1, k = i + 1; j >= 0 && k <= length; -- j, ++ k) {
                    //cout << "odd: " << j << "\t" << s[j] << "\t" << k << "\t" << s[k] << endl;
                if (s[j] == s[k]) {
                    cur_odd ++;
                    if (cur_odd > max) {
                        max = cur_odd;
                        index = i;
                        is_odd = true;
                    }
                } else {
                    break;
                }
            }

            for (int j = i - 1, k = i; j >= 0 && k < length; -- j, ++ k) {
                    //cout << "even: " << j << "\t" << s[j] << "\t" << k << "\t" << s[k] << endl;
                if (s[j] == s[k]) {
                    cur_even ++;
                    if (cur_even >= max) {
                        max = cur_even;
                        index = i;
                        is_odd = false;
                    }
                } else {
                    break;
                } 
            }
        }
        cout << is_odd << endl << index << endl << max << endl;
        if (max == 0) {
            return s.substr(0, 1);
        }

        string str;
        if (is_odd) {
            str = s.substr(index - max + 1, max * 2 - 1);
        } else {
            str = s.substr(index - max, max * 2);
        }
            //string str = s.substr(index - max + 1, max * 2);
        return str;
    }

    string longestPalindrome_v2(string s) {
        int n = s.size(), len = 0, start = 0;
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(right < n && s[right+1] == s[right]) right++;
            i = right;
            while(left > 0 && right < n-1 && s[left-1] == s[right+1]){
                left--;
                right++;
            }
            
            if(len < right-left+1){
                len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, len);
    }
};

int main()
{
    Solution* so = new Solution();
    string s = "abcda";
    //cin >> s;
    string result = so->longestPalindrome(s);
    cout << result << endl;
    return 0;
}
