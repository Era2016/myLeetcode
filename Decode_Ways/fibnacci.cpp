#include <iostream>
#include <vector>

using namespace std;

class Fib {
    public:
        int fib(int num) {
            if (num == 1) {
                return 0;
            } else if (num == 2) {
                return 1;
            } else {
                return fib(num - 1) + fib(num - 2);
            }
        }
};

int main()
{
    Fib* f = new Fib();
    for (int i = 1; i <= 10; ++ i) {
        cout << f->fib(i) << endl;
    }
    //cout << f->fib(3) << endl;
    return 0;
}
