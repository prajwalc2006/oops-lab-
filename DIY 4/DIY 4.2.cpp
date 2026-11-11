#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
    int* data;
    size_t capacity, size = 0;
public:
    explicit Stack(size_t cap) : data(cap ? new int[cap] : nullptr), capacity(cap) {
        if (!cap) throw invalid_argument("Capacity must be positive.");
    }
    ~Stack() { delete[] data; }
    void push(int value) {
        if (size == capacity) throw overflow_error("Stack is full.");
        data[size++] = value;
    }
    int pop() {
        if (!size) throw underflow_error("Stack is empty.");
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
