#include <iostream>
#include <cstring>
using namespace std;

class Mystring {
    char* data;

public:
    Mystring(const char* s) {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    Mystring(const Mystring& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    ~Mystring() {
        delete[] data;
    }

    void print() const {
        cout << data << endl;
    }
};

int main() {
    Mystring a("hardware");
    Mystring b = a;
    a.print();
    b.print();
    return 0;
}