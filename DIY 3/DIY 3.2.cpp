#include <iostream>
using namespace std;

class Counter {
    int value = 0;
public:
    void increment() { ++value; }
    void reset() { value = 0; }
    int get() const { return value; }
};

int main() {
    Counter counters[3];
    counters[0].increment();
    counters[1].increment();
    counters[1].increment();
    counters[2].reset();
    for (int i = 0; i < 3; ++i)
        cout << "Counter " << i + 1 << ": " << counters[i].get() << '\n';
}
