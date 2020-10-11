#include <iostream>
#include <vector>
#include <unordered_map>

//basic_string substr (size_type pos = 0, size_type len = npos) const;
using namespace std;

void print(vector<string> v);
void print(unordered_map<string, vector<string> > v);

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string> > m;
        return wordBreak(s, wordDict, m);
    }
private:
    vector<string> wordBreak(string s, vector<string>& wordDict, unordered_map<string, vector<string> >& m) {
        if (s.length() == 0) {
            return {""};
        }
        if (m.count(s) != 0) {
            return m[s];
        }

        vector<string> v;
        for (string word: wordDict) {
            if (s.substr(0, word.size()) != word) {
                continue;
            }
            vector<string> res = wordBreak(s.substr(word.size()), wordDict, m);
            //print(res);
            for (string str: res) {
                //string tmp = word + (str.empty() ? "" : " ") + str;
                //cout << "insert val: " << tmp << endl;
                //v.push_back(tmp);
                v.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        m[s] = v;
        return v;
    }
};

void print(vector<string> v) {
    cout << "====start====" << endl;
    for (string str: v) {
        cout << str << endl;
    }
    cout << "====end====" << endl << endl;
}

void print(unordered_map<string, vector<string> > v) {
    unordered_map<string, vector<string> >::iterator iter = v.begin();
    for (; iter != v.end(); iter ++) {
        cout << "key: "<< iter->first << endl;
        cout << "value: " << endl;
        print(iter->second);
    }

}

int main() {
	Solution* so = new Solution();
	vector<string> v = {"cat", "cats", "and", "sand", "dog"};
	string str = "catsanddog";
	vector<string> val = so->wordBreak(str, v);
    print(val);

	v = {"apple", "pen", "applepen", "pine", "pineapple"}; 
	str = "pineapplepenapple";
	val = so->wordBreak(str, v);
    print(val);

	v = {"cats", "dog", "sand", "and", "cat"};
	str = "catsandog";
	val = so->wordBreak(str, v);
    print(val);
}
