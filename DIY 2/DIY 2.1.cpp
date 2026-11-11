#include <iostream>
using namespace std;

double volume(double side) { return side * side * side; }
double volume(double length, double width, double height) {
    return length * width * height;
}
double volume(double radius, double height) {
    const double pi = 3.141592653589793;
    return pi * radius * radius * height;
}

int main() {
    cout << "Cube (side 3): " << volume(3.0) << '\n';
    cout << "Cuboid (2 x 3 x 4): " << volume(2.0, 3.0, 4.0) << '\n';
    cout << "Cylinder (radius 2, height 5): " << volume(2.0, 5.0) << '\n';
}
