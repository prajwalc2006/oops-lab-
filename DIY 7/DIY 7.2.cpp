#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Shape {
protected:
    string name;
public:
    explicit Shape(string value) : name(move(value)) { cout << "Shape constructor\n"; }
};
class Polygon : public Shape {
protected:
    int sides;
public:
    Polygon(string value, int count) : Shape(move(value)), sides(count) {
        cout << "Polygon constructor\n";
    }
};
class Rectangle : public Polygon {
    double length, width;
public:
    Rectangle(double l, double w)
        : Polygon("Rectangle", 4), length(l), width(w) {
        cout << "Rectangle constructor\n";
    }
    double area() const { return length * width; }
};

int main() {
    Rectangle rectangle(4, 3);
    cout << "Area: " << rectangle.area() << '\n';
}
