#include <iostream>
using namespace std;

class Order {
    static int nextId;
    int id;
public:
    Order() : id(nextId++) {}
    int getId() const { return id; }
};
int Order::nextId = 1001;

int main() {
    Order first, second, third;
    cout << first.getId() << '\n' << second.getId() << '\n' << third.getId() << '\n';
}
