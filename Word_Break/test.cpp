#include <iostream>

using namespace std;

int main() {
    string s = "hello";
    cout << "origin: " << s << endl;

    cout << "length: " << s.length() << endl;

    string slice = s.substr(0, 1);
    cout << "slice: " << slice << endl;
}
