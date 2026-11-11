#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> values = {2, 3, 4, 5};
    long long product = accumulate(values.begin(), values.end(), 1LL,
        [](long long result, int value) { return result * value; });
    int evenSum = accumulate(values.begin(), values.end(), 0,
        [](int sum, int value) { return sum + (value % 2 == 0 ? value : 0); });
    cout << "Product: " << product << "\nSum of even values: " << evenSum << '\n';
}
