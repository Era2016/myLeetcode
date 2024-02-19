#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int main()
{
    //string str = "123";
    char str[] = "   -1a23a";
    int result = atoi(str);
    cout << result << endl;
    cout << INT_MAX << "\t" << INT_MIN << endl;
    return 0;
}
