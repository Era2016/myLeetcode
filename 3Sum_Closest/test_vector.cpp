#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int >v;
    v.push_back(10);
    v.push_back(20);
    cout << v.at(0) << endl << v.at(1) << endl;
    return 0;
}
