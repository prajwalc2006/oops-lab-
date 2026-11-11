#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

long long counter = 0;
mutex counterMutex;

void addSafely(int times) {
    for (int i = 0; i < times; ++i) {
        lock_guard<mutex> lock(counterMutex);
        ++counter;
    }
}

int main() {
    thread first(addSafely, 100000);
    thread second(addSafely, 100000);
    first.join();
    second.join();
    cout << "Counter: " << counter << " (expected 200000)\n";
}
