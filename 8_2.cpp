#include <iostream>
using namespace std;

class Base {
public:
    void normal() { 
        cout << "Base::normal (early binding)\n"; 
    }
    
    virtual void special() { 
        cout << "Base::special\n"; 
    }
};

class Derived : public Base {
public:
    void normal() { 
        cout << "Derived::normal\n"; 
    }
    
    void special() override { 
        cout << "Derived::special (late binding)\n"; 
    }
};

int main() {
    Derived d;
    Base *p = &d; // Base pointer pointing to a derived object

    // EARLY BINDING: Determined at compile-time by the pointer type (Base*)
    p->normal();  

    // LATE BINDING: Determined at runtime by the actual object type (Derived)
    p->special(); 

    return 0;
}