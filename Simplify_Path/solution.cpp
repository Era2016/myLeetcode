#include <iostream>
#include <deque>

using namespace std;
class Solution {
public:
    string SimplyPath(string path) {
        deque<string> dq;
        int cursor = 1;
        while (cursor < path.length()) {
            int index = path.find('/', cursor);
            //cout << "index: " << index << endl;
            if (index == string::npos) {
                string str = path.substr(cursor, -1);
                //cout << "value: " << str << endl;
                if (str == "..") {
                    if (!dq.empty()) {
                        dq.pop_back();
                    }
                } else if (str == ".") {
                    ;
                } else {
                    dq.push_back(str);
                }
                break;
            }
            string str = path.substr(cursor, index-cursor);
            //cout << "value: " << str << endl;
            if (str == "." || str == "") {
                ;
            } else if (str == "..") {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            } else {
                dq.push_back(str);
            }
            
            cursor = index+1;
        }

        string result;
        for (auto str: dq) {
            result += "/" + str;
        }
        return (result == "")? "/": result;
    }
};

int main() {
    Solution *so = new Solution();
    // cout << so->SimplyPath("/abc/./def") << endl;
    // cout << so->SimplyPath("/abc/../def") << endl;
    // cout << so->SimplyPath("/home") << endl;
    // cout << so->SimplyPath("/../") << endl;
    // cout << so->SimplyPath("/home//foo/") << endl;
    // cout << so->SimplyPath("/a/./b/../../c/") << endl;
    cout << so->SimplyPath("/a//b////c/d//././/..") << endl; // /a/b/c
    cout << so->SimplyPath("/a//b////c/d//././/../.") << endl; // /a/b/c
    cout << so->SimplyPath("/a//b////c/d//././/..//") << endl; // /a/b/c
}
