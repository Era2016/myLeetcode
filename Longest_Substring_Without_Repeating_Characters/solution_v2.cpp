#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        //cout << length << endl;
        if (length <= 1) {
            return length;
        } 

        set<char> ss;
        int len = 0;
        int max = 0;
        for (int i = 0; i < length; ++ i) {
            for (int j = i; j < length; ++ j) {
                if (ss.find(s[j]) == ss.end()) {
                    ss.insert(s[j]);
                    len ++;
                    cout << "cur len : " << len << endl;
                    if (max < len) {
                        max = len;
                    }
                } else {
                    ss.clear();
                    len = 0;
                    break;
                }              
            }
        }

        return max;
    }

    int lengthOfLongestSubstring_v2(string s) {
        int flags[256];
        for (int i = 0; i < 256; i++)
            flags[i] = -1;
        
        int longest = 0;
        int i = 0;
        int collision = -1;
        while (s[i] != 0)
        {
            if (flags[s[i]] != -1)
                collision = (collision > flags[s[i]] ? collision : flags[s[i]]);
            flags[s[i]] = i;
            longest = (i - collision > longest ? i - collision : longest);
            i++;
        }
        
        return longest;
    }

    // hash m key:存放的是字符;value:字符串中的当前顺序
    int lengthOfLongestSubstring_v3(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++ i) {
            // m[s[i]] < left 是由于m[s[j]]已经过期，是上一次的字符顺序，需要更新
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }

    int lengthOfLongestSubstring_v4(string s) {
        vector<int> m(256, -1);
        int res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i + 1;
            res = max(res, i - left + 1);
        }
        return res;
    }

    // 一个[walker, runner]滚动区间，向前运动，max{runner-walker}就是最大值
    int lengthOfLongestSubstring_v5(string s) {
        if (s.length() == 0) 
            return 0;
        set<char> ss;
        int max_length = 0;
        int walker = 0;
        int runner = 0;
        while (runner < s.length()) {
            // ss中存在s[runner]
            if (ss.find(s[runner]) != ss.end()) {
                if (max_length < runner - walker) {
                    max_length = runner - walker;
                }
                while (s[walker] != s[runner]) {
                    ss.erase(s[walker]);
                    walker ++;
                }
                walker ++;
            } else {
                ss.insert(s[runner]);
            }
            runner ++;
        }

        max_length = max(max_length, runner - walker);
        return max_length;
    }
};

int main()
{
    Solution* so = new Solution();
    //string s = "abcabcbb";
    //string s = "abbca";
    string s = "abcade";

    int result = so->lengthOfLongestSubstring_v5(s);
    cout << result << endl;
    return 0;
}
