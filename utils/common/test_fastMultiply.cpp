#include <iostream>

long long fastMultiply(long long a, long long b) {
    long long result = 0;
    while (b != 0) {
        if (b & 1) result += a;

        a <<= 1;
        b >>= 1;
    }
    return result;
}

int main() {
    long long a = 123456789;
    long long b = 987654321;
    long long product = fastMultiply(a, b);
    std::cout << "Product of " << a << " and " << b << " is: " << product << std::endl;
    return 0;
}
