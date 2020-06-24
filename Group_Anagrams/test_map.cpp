#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, string> mapStudent;  

    mapStudent[1] = "student_one";  

    mapStudent[3] = "student_two";  

    mapStudent[3] = "student_three";  

    map<int, string>::iterator iter;  

    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)  
        cout<<iter->first<<' '<<iter->second<<endl;   
}
