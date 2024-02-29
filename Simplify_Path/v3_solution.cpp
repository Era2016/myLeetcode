#include <deque>
#include <iostream>

using std::deque;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string SimplyPath(string path) {
        deque<string> dq;
        int index = path.find('/', 0);
        while (true) {
            int newIndex = path.find('/', index+1);
            if (newIndex == -1) {
                string str = path.substr(index+1, -1);
                if (str == "..") {
                    if (!dq.empty()) {
                        dq.pop_back();
                    }
                } else if(str == "." || str == "") {
                    ;
                } else {
                    dq.push_back(str);
                }
                break;
            }
            string str = path.substr(index+1, newIndex-index-1);
            if (str == "..") {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            } else if (str == "." || str == "") {
                ;
            } else {
                dq.push_back(str);
            }

            index = newIndex;
        }

        string str = "/";
        if (!dq.empty()) {
            for (auto s: dq) {
                str += s + "/";
            } 
            str.pop_back();
        }
        return str;
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
