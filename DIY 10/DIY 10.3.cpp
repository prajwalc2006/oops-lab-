#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    ifstream input("students.txt");
    if (!input) {
        cerr << "Create students.txt with one `name marks` record per line.\n";
        return 1;
    }

    vector<Student> students;
    Student student;
    while (input >> student.name >> student.marks) students.push_back(student);
    if (!input.eof()) {
        cerr << "Invalid student record in students.txt.\n";
        return 1;
    }
    if (students.empty()) {
        cerr << "students.txt has no student records.\n";
        return 1;
    }

    const Student& topper = *max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) { return a.marks < b.marks; });
    cout << "Topper: " << topper.name << " (" << topper.marks << ")\n";
}
