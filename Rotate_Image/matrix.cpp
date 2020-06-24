#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int length = 50;

    for (int i = 1, j = 1; i < length; ++ i) {
        cout << setw(2) <<i << " ";
        if (i % 5 == 0) {
            j ++;
            cout << endl;
        }
        if (j == 6) {
            break;
        }
    }
    return 0;
}
