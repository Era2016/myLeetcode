#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<string> > groupAnagrams(vector<string>& strs) {
            map<string, vector<string> >m;
            for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); ++ iter) {
                //string sortedStr = stringSort(*iter);
                string sortedStr = *iter;
                sort(sortedStr.begin(), sortedStr.end());
                map<string, vector<string> >::iterator it = m.find(sortedStr);
                if (it == m.end()) {
                    vector<string> v;
                    v.push_back(*iter);
                    m.insert(pair<string, vector<string> >(sortedStr, v));
                } else {
                    //vector<string> v = it->second;
                    //v.push_back(*iter);
                    (it->second).push_back(*iter);
                }
            } 

            vector<vector<string> > vv;
            for (map<string, vector<string> >::iterator iter = m.begin(); iter != m.end(); ++ iter) {
                vv.push_back(iter->second);
            }
            return vv;
        }

        string stringSort (string str) {
            for (int i = 1; i < (int)str.length(); ++ i) {
                int j = i - 1;
                int temp = str[j+1];
                while (j >= 0 && str[j] > temp) {
                    str[j+1] = str[j];
                    j --;
                }
                str[j+1] = temp;
            }
            return str;
        }
        vector<vector<string>> groupAnagrams_v2(vector<string>& strs) {
            map<string, vector<string> > mp;
            vector<vector<string> > res;
            for(string s: strs){
                string temp = s;
                sort(temp.begin(), temp.end());
                mp[temp].push_back(s);
            }
            for(auto w: mp){
                vector<string> temp_res = w.second;
                res.push_back(temp_res);
            }
            return res;
        }
};

int main()
{
    Solution* so = new Solution();
    //string str = so->sort("a");
    //cout << str << endl;
    vector<string> v;
    v.push_back("eat");
    v.push_back("tea");
    v.push_back("tan");
    v.push_back("ate");
    v.push_back("nat");
    v.push_back("bat");

    vector<vector<string> > vv = so->groupAnagrams(v);
    for (vector<vector<string> >::iterator iter = vv.begin(); iter != vv.end(); ++ iter) {
        for (vector<string>::iterator it = iter->begin(); it != iter->end(); ++ it) {
            cout << *it << ",";
        }
        cout << endl;
    }
    return 0;
}
