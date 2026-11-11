#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};
class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const override { return 3.141592653589793 * radius * radius; }
};
class Square : public Shape {
    double side;
public:
    explicit Square(double s) : side(s) {}
    double area() const override { return side * side; }
};
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return base * height / 2; }
};

unique_ptr<Shape> makeShape(const string& kind) {
    if (kind == "circle") return make_unique<Circle>(2);
    if (kind == "square") return make_unique<Square>(3);
    if (kind == "triangle") return make_unique<Triangle>(4, 5);
    throw invalid_argument("Choose circle, square, or triangle.");
}

int main() {
    size_t count;
    cout << "How many shapes? ";
    if (!(cin >> count)) return 1;
    vector<unique_ptr<Shape>> shapes;
    try {
        for (size_t i = 0; i < count; ++i) {
            string kind;
            cout << "Shape " << i + 1 << " (circle/square/triangle): ";
            if (!(cin >> kind)) return 1;
            shapes.push_back(makeShape(kind));
        }
    } catch (const invalid_argument& error) {
        cerr << error.what() << '\n';
        return 1;
    }
    for (const auto& shape : shapes) cout << "Area: " << shape->area() << '\n';
}
