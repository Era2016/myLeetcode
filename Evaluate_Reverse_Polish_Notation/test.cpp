#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string s = "11";
    int i = stoi(s);
    cout << i << endl;
    bool flag = isdigit(i);
    cout << flag << endl;
}
