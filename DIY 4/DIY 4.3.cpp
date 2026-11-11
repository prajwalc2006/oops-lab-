#include <iostream>
using namespace std;

class Tracer {
    int id;
public:
    explicit Tracer(int value) : id(value) { cout << "Created " << id << '\n'; }
    ~Tracer() { cout << "Destroyed " << id << '\n'; }
};

int main() {
    for (int id = 1; id <= 3; ++id) {
        Tracer* item = new Tracer(id);
        delete item;
    }
}
