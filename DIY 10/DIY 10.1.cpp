#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    ifstream input("nums.txt");
    if (!input) {
        cerr << "Create nums.txt with one or more integers, then run again.\n";
        return 1;
    }

    long long value, sum = 0, minimum = 0, maximum = 0;
    size_t count = 0;
    while (input >> value) {
        if (!count) minimum = maximum = value;
        if (value < minimum) minimum = value;
        if (value > maximum) maximum = value;
        sum += value;
        ++count;
    }
    if (!input.eof()) {
        cerr << "nums.txt contains a value that is not an integer.\n";
        return 1;
    }
    if (!count) {
        cerr << "nums.txt contains no integers.\n";
        return 1;
    }
    cout << "Count: " << count << "\nSum: " << sum
         << "\nMin: " << minimum << "\nMax: " << maximum << '\n';
}
