#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Person {
protected:
    string name;
public:
    explicit Person(string value) : name(move(value)) {}
    void showPerson() const { cout << "Name: " << name << '\n'; }
};
class Student : virtual public Person {
protected:
    int studentId;
public:
    Student(string name, int id) : Person(move(name)), studentId(id) {}
};
class Employee : virtual public Person {
protected:
    int employeeId;
public:
    Employee(string name, int id) : Person(move(name)), employeeId(id) {}
};
class TA : public Student, public Employee {
public:
    TA(string name, int student, int employee)
        : Person(name), Student(name, student), Employee(name, employee) {}
    void show() const {
        showPerson();
        cout << "Student ID: " << studentId << ", Employee ID: " << employeeId << '\n';
    }
};

int main() {
    TA assistant("Meera", 204, 501);
    assistant.show();
}
