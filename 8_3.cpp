#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() const = 0;             // Pure virtual function
    virtual ~Animal() { cout << "~Animal\n"; }  // Virtual destructor ensures full cleanup
};

class Dog : public Animal {
public:
    void speak() const override { cout << "Woof\n"; }
    ~Dog() { cout << "~Dog\n"; }
};

int main() {
    // Upcasting (Implicit & Safe): Derived pointer assigned to Base pointer
    Animal *a = new Dog(); 
    
    // Downcasting (Base to Derived): Checked safely at runtime using dynamic_cast
    if (Dog *d = dynamic_cast<Dog*>(a)) {
        cout << "downcast ok-> ";
        d->speak(); // Outputs: Woof
    }
    
    delete a; // Triggers ~Dog then ~Animal due to the virtual destructor
    return 0;
}