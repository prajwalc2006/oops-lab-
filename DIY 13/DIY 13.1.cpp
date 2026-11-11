#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

class Stack {
    size_t capacity, size = 0;
    unique_ptr<int[]> data;
public:
    explicit Stack(size_t cap) : capacity(cap), data(make_unique<int[]>(cap)) {}
    void push(int value) {
        if (size == capacity) throw runtime_error("Stack is full.");
        data[size++] = value;
    }
    int pop() {
        if (!size) throw runtime_error("Stack is empty.");
        return data[--size];
    }
    bool empty() const { return size == 0; }
};

int main() {
    Stack stack(3);
    stack.push(10);
    stack.push(20);
    while (!stack.empty()) cout << stack.pop() << '\n';
}
