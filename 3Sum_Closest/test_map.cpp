#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int, string> mm;
    mm.insert(pair<int, string>(1, "tom"));
    mm.insert(pair<int, string>(2, "peter"));


    for (map<int, string>::iterator iter=mm.begin(); iter != mm.end(); iter ++) {
        cout << iter->first << "\t" << iter->second << endl;
    }

    return 0;
}
