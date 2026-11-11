#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(string employeeName, int employeeId)
        : name(move(employeeName)), id(employeeId) {}
    virtual void print() const {
        cout << "Name: " << name << ", ID: " << id;
    }
    virtual ~Employee() = default;
};
class Manager : public Employee {
    int teamSize;
public:
    Manager(string name, int id, int size) : Employee(move(name), id), teamSize(size) {}
    void print() const override {
        Employee::print();
        cout << ", team size: " << teamSize << '\n';
    }
};
class Engineer : public Employee {
    string skill;
public:
    Engineer(string name, int id, string expertise)
        : Employee(move(name), id), skill(move(expertise)) {}
    void print() const override {
        Employee::print();
        cout << ", skill: " << skill << '\n';
    }
};

int main() {
    Manager manager("Asha", 101, 5);
    Engineer engineer("Ravi", 102, "C++");
    manager.print();
    engineer.print();
}
