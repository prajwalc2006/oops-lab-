#include <iostream>
using namespace std;
inline int square(int x) { return x * x; }
double area(double radius) { return 3.14159 * radius * radius; }
int area(int length, int breadth) { return length * breadth; }
double area(double base, double height) { return 0.5 * base * height; }

int main() {
    cout << "Square(6) = " << square(6) << endl;
    cout << "Circle(r=20) = " << area(20.0) << endl;
    cout << "Rectangle(4x5) = " << area(4, 5) << endl;
    cout << "Triangle(b=30,h=80) = " << area(30.0, 80.0) << endl;
    return 0;
}