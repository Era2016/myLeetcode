#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> v);

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        // sort by the alpha
        vector<string> v = sortByAlphabet(nums);
        //print(v);

        // strcat the nums
        return stringSplice(v);
    }
private:
    bool static cmp(string a, string b) {
        return a+b > b+a;
    }
    vector<string> sortByAlphabet(vector<int>& nums) {
        vector<string> v;
        for (int i = 0; i < (int)nums.size(); i ++) {
            string str = to_string(nums[i]); 
            v.push_back(str);
        }

        sort(v.begin(), v.end(), cmp);        
        return v;
    }

    string stringSplice(vector<string> v) {
        string str;
        for (int i = 0; i < (int)v.size(); i ++) {
            str += v[i];
        } 

        if (!v.empty() && v[0] == "0") {
            str = "0";
        }
        return str;
    }
};

void print(vector<string> v) {
    for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter ++) {
        cout << *iter << "\t";
    }
    cout << endl;
}

int main() {
    Solution* so = new Solution();
    vector<int> v;
    string str;

    v = {3,30,34,5,9};
    str = so->largestNumber(v);
    cout << "result: " << str << endl;

    v = {0,0};
    str = so->largestNumber(v);
    cout << "result: " << str << endl;

    v = {10,2};
    str = so->largestNumber(v);
    cout << "result: " << str << endl;
}
