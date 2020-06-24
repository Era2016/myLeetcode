#include <iostream>

using namespace std;

int main()
{
    string s = "abccba";
    int index = 2;
    int max = 3;//s.length();

    cout << index << "\t" << max << endl;
    // is_odd
    //cout << s.substr(index-max+1, max * 2) << endl;
    // is_even
    cout << s.substr(index-max+1, max * 2) << endl;
    return 0;
}
