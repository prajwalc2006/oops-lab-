#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    size_t count;
    cout << "How many numbers? ";
    if (!(cin >> count)) return 1;
    if (count < 3) {
        cerr << "Enter at least three numbers.\n";
        return 1;
    }

    priority_queue<int> largest;
    cout << "Enter " << count << " integers: ";
    for (size_t i = 0; i < count; ++i) {
        int value;
        if (!(cin >> value)) {
            cerr << "Invalid integer input.\n";
            return 1;
        }
        largest.push(value);
    }
    cout << "Three largest: ";
    for (int i = 0; i < 3; ++i) {
        cout << largest.top() << ' ';
        largest.pop();
    }
    cout << '\n';
}
