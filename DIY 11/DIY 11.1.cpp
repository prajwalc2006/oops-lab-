#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    vector<pair<string, int>> students = {
        {"Asha", 88}, {"Ravi", 75}, {"Meera", 92}, {"Dev", 81}
    };
    sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    for (const auto& student : students)
        cout << student.first << ' ' << student.second << '\n';
}
