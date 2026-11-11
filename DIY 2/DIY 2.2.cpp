#include <iostream>
#include <stdexcept>
using namespace std;

long long power(int base, int exp = 2) {
    if (exp < 0) throw invalid_argument("Exponent must be non-negative.");
    long long result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}

int main() {
    try {
        cout << "power(5) = " << power(5) << '\n';
        cout << "power(2, 10) = " << power(2, 10) << '\n';
    } catch (const invalid_argument& error) {
        cerr << error.what() << '\n';
        return 1;
    }
}
