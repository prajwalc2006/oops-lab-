#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    vector<pair<string, int>> values = {
        {"Asha", 88}, {"Ravi", 75}, {"Meera", 92}, {"Dev", 81}
    };
    sort(values.begin(), values.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    for (const auto& value : values) cout << value.first << ' ' << value.second << '\n';
}
