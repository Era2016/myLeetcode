#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "123";
    for (int i = 0; i < (int)str.length(); ++ i) 
    {
        str[i] = i + 'a';
    }
    cout  << str<< endl;
}
