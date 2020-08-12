#include <iostream>

using namespace std;

int main() {

	int length = 8;
    for (int i = 1; i < length; i = i * 2) {
    	cout << "current round: " << i << endl;
    	for (int j = 0; j < length - i; j += i*2) {
    		cout <<"point" << "\t"<< j << "\t" << j+i << endl;
    	}
    }

    return 0;
}