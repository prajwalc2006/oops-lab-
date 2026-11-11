#include <iostream>
using namespace std;

class Counter {
    static int created, alive;
public:
    Counter() { ++created; ++alive; }
    Counter(const Counter&) { ++created; ++alive; }
    ~Counter() { --alive; }
    static int totalCreated() { return created; }
    static int currentlyAlive() { return alive; }
};
int Counter::created = 0;
int Counter::alive = 0;

int main() {
    Counter first;
    {
        Counter group[3];
        cout << "Created: " << Counter::totalCreated()
             << ", alive: " << Counter::currentlyAlive() << '\n';
    }
    cout << "After group leaves scope, alive: " << Counter::currentlyAlive() << '\n';
}
