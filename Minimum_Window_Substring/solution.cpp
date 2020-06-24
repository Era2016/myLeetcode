#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Solution {
    public:
        string minWindow(string s, string t) {
            map<char, int> mm = this->initMap(t);
            map<char, int>::iterator iter;
            int minLength = 0;
            int minLeft;
            int left = 0;
            for (int i = 0; i < (int)s.length(); ++ i) {
                iter = mm.find(s[i]);
                if (iter != mm.end()) {
                    if (iter->second == 1) {
                        mm.erase(iter);
                        if (mm.empty()) {
                            int currLength = i - left + 1;
                            if (currLength < minLength) {
                                minLength = currLength;
                                minLeft = left;
                            }
                            mm = this->initMap(t);
                            while (mm.find(s[left]) == mm.end()) {
                                left ++;
                            }
                        }
                    } else {
                        mm.insert(pair<char, int>(iter->first, iter->second - 1));
                    }
                }
            }

            return s.substr(minLeft, minLength);
        }

        map<char, int> initMap(string t) {
            map<char, int> mm;
            map<char, int>::iterator iter;
            for (int i = 0; i < (int)t.length(); ++ i) {
                iter = mm.find(t[i]);
                if (iter == mm.end()) {
                    mm.insert(pair<char, int>(t[i], 1));
                } else {
                    mm.insert(pair<char, int>(iter->first, iter->second + 1));
                }
            }
            return mm;
        }

        string minWindow_v2(string S, string T) {
            if (T.size() > S.size()) return "";
            string res = "";
            int left = 0, count = 0, minLen = S.size() + 1;
            map<char, int> m;
            for (int i = 0; i < (int)T.size(); ++i) {
                if (m.find(T[i]) != m.end()) ++m[T[i]];
                else m[T[i]] = 1;
            }
            for (int right = 0; right < (int)S.size(); ++right) {
                if (m.find(S[right]) != m.end()) {
                    --m[S[right]];
                    if (m[S[right]] >= 0) ++count;
                    while (count == (int)T.size()) {
                        if (right - left + 1 < minLen) {
                            minLen = right - left + 1;
                            res = S.substr(left, minLen);
                        }
                        if (m.find(S[left]) != m.end()) {
                            ++m[S[left]];
                            if (m[S[left]] > 0) --count;
                        }
                        ++left;
                    }
                }
            }
            return res;
        }

};
