#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10);

    /*for (int i = 0; i < 11; i ++) {
        v.push_back(i);
    }*/

    cout << "begin :: " << endl;
    /*for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++ iter) {
        cout << *iter << endl;
    }*/

    for (int i = 0; i < 30; ++ i) {
        cout << v[i] << endl;
    }

    return 0;
}
