#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5, 9, 8, 7};
    swap(v1[0], v1[2]);
    sort(v1.begin()+5, v1.end());

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;
}
