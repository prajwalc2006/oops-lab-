#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
    virtual void show() const { cout << "Base\n"; }
#ifdef DEMONSTRATE_LEAK
    ~Base() { cout << "Base destroyed\n"; }
#else
    virtual ~Base() { cout << "Base destroyed\n"; }
#endif
};
class Derived : public Base {
    int* memory;
public:
    Derived() : memory(new int[100]{}) { cout << "Derived allocated memory\n"; }
    void show() const override { cout << "Derived\n"; }
    ~Derived() {
        delete[] memory;
        cout << "Derived released memory\n";
    }
};

int main() {
    Base* object = new Derived();
    object->show();
    delete object;
    cout << "Without a virtual Base destructor, Derived's destructor is skipped; "
            "define DEMONSTRATE_LEAK and use AddressSanitizer to observe the leak.\n";
}
