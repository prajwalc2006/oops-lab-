#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
    virtual void show() const { cout << "Base\n"; }
    virtual ~Base() { cout << "Base destroyed\n"; }
};
class Derived : public Base {
    unique_ptr<int[]> memory;
public:
    Derived() : memory(new int[100]{}) { cout << "Derived allocated memory\n"; }
    void show() const override { cout << "Derived\n"; }
    ~Derived() override { cout << "Derived released memory\n"; }
};

int main() {
    unique_ptr<Base> object = make_unique<Derived>();
    object->show();
    cout << "The virtual base destructor ensures Derived is destroyed first.\n";
}
