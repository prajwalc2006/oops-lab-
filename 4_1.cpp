#include <iostream>

using namespace std;

class Tracer {
    int id;

public:
    Tracer(int i) : id(i) {
        cout << "construct #" << id << endl;
    }

    ~Tracer() {
        cout << "destruct #" << id << endl;
    }
};

int main() {
    cout << "Enter block" << endl;

    {
        Tracer a(1), b(2);
        cout << "... working ..." << endl;
    }

    cout << "left block" << endl;
    return 0;
}
