//
//  main.hpp
//  Group_Anagrams
//
//  Created by Fan on 31/12/2017.
//

#ifndef main_hpp
#define main_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> >m;
        for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); ++ iter) {
            string sortedStr = sort(*iter);
            //cout <<"sorted:: " <<sortedStr<< endl ;
            map<string, vector<string> >::iterator it = m.find(sortedStr);
            if (it == m.end()) {
                vector<string> v;
                v.push_back(*iter);
                m.insert(pair<string, vector<string> >(sortedStr, v));
            } else {
                //cout << "come on:: " << *iter << endl;
                vector<string> v = it->second;
                v.push_back(*iter);
                for (vector<string>::iterator it = v.begin(); it != v.end(); ++ it) {
                    cout << "iterator::" << sortedStr << "::"<< *it << ",";
                }
                cout << endl;
                m.insert(pair<string, vector<string> >(sortedStr, v));
            }
        }
        
        vector<vector<string> > vv;
        for (map<string, vector<string> >::iterator iter = m.begin(); iter != m.end(); ++ iter) {
            vv.push_back(iter->second);
            /*for (vector<string>::iterator i = iter->second.begin(); i != iter->second.end(); ++ i) {
             cout << "iter :: " << *i << ",";
             }*/
            //cout << endl;
        }
        return vv;
    }
    
    string sort (string str) {
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
#endif /* main_hpp */
