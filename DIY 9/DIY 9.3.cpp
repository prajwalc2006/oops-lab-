#include <iostream>
#include <stdexcept>
using namespace std;

class MathError : public runtime_error {
public:
    MathError() : runtime_error("Math error.") {}
};
class DivideByZero : public MathError {
public:
    DivideByZero() : MathError() {}
};

int divide(int a, int b) {
    if (!b) throw DivideByZero();
    return a / b;
}

int main() {
    try {
        divide(10, 0);
    } catch (const MathError& error) {
        cout << "Base catch handled the derived exception: " << error.what() << '\n';
    }

    try {
        divide(10, 0);
    } catch (const DivideByZero&) {
        cout << "Correct order: caught DivideByZero first.\n";
    } catch (const MathError& error) {
        cout << error.what() << '\n';
    }
}
