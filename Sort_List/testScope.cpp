#include <iostream>

using namespace std;

int main() {
    int a = 1;
    for (int i = 1; i < 4; i ++) {
        int b = a + 1;
        int a = 5;
        cout << b << endl; // output 2
    }
}