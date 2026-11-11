#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Overflow : public runtime_error {
public:
    Overflow() : runtime_error("Stack is full.") {}
};
class Underflow : public runtime_error {
public:
    Underflow() : runtime_error("Stack is empty.") {}
};
class Stack {
    vector<int> data;
    size_t capacity;
public:
    explicit Stack(size_t cap) : capacity(cap) {}
    void push(int value) {
        if (data.size() == capacity) throw Overflow();
        data.push_back(value);
    }
    int pop() {
        if (data.empty()) throw Underflow();
        int value = data.back();
        data.pop_back();
        return value;
    }
};

int main() {
    Stack stack(2);
    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);
    } catch (const Overflow& error) {
        cerr << error.what() << '\n';
    }
    try {
        cout << "Popped: " << stack.pop() << '\n';
        cout << "Popped: " << stack.pop() << '\n';
        stack.pop();
    } catch (const Underflow& error) {
        cerr << error.what() << '\n';
    }
}
