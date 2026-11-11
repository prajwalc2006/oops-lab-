#include <iostream>
using namespace std;

class Complex {
    double real = 0, imag = 0;
public:
    void setData(double r, double i) { real = r; imag = i; }
    void display() const {
        cout << real << (imag < 0 ? " - " : " + ") << (imag < 0 ? -imag : imag) << "i";
    }
};

int main() {
    Complex values[3];
    values[0].setData(2, 3);
    values[1].setData(-1, 4);
    values[2].setData(5, -2);
    for (const Complex& value : values) {
        value.display();
        cout << '\n';
    }
}
