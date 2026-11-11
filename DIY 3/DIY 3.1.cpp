#include <iostream>
using namespace std;

class Rectangle {
    double length = 0, width = 0;
public:
    bool setLength(double value) {
        if (value < 0) return false;
        length = value;
        return true;
    }
    bool setWidth(double value) {
        if (value < 0) return false;
        width = value;
        return true;
    }
    double area() const { return length * width; }
    double perimeter() const { return 2 * (length + width); }
};

int main() {
    Rectangle rectangle;
    if (!rectangle.setLength(5) || !rectangle.setWidth(3)) return 1;
    cout << "Area: " << rectangle.area()
         << "\nPerimeter: " << rectangle.perimeter() << '\n';
    cout << "Negative length rejected: " << boolalpha
         << !rectangle.setLength(-2) << '\n';
}
