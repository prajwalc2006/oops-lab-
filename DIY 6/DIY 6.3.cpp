#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

class SafeArray {
    size_t size;
    unique_ptr<int[]> data;
public:
    explicit SafeArray(size_t n) : size(n), data(new int[n]{}) {}
    int& operator[](size_t index) {
        if (index >= size) throw out_of_range("Array index out of range.");
        return data[index];
    }
    int operator[](size_t index) const {
        if (index >= size) throw out_of_range("Array index out of range.");
        return data[index];
    }
    size_t length() const { return size; }
};

int main() {
    SafeArray values(3);
    for (size_t i = 0; i < values.length(); ++i) values[i] = static_cast<int>(i + 1) * 10;
    try {
        for (size_t i = 0; i <= values.length(); ++i) cout << values[i] << '\n';
    } catch (const out_of_range& error) {
        cerr << error.what() << '\n';
    }
}
