#include <iostream>
using namespace std;

class Money {
    long long paise;
    explicit Money(long long totalPaise) : paise(totalPaise) {}
public:
    Money(long long rupees, int extraPaise)
        : paise(rupees * 100 + extraPaise) {}
    Money operator+(const Money& other) const { return Money(paise + other.paise); }
    Money operator-(const Money& other) const { return Money(paise - other.paise); }
    friend ostream& operator<<(ostream& out, const Money& money) {
        long long amount = money.paise;
        if (amount < 0) { out << '-'; amount = -amount; }
        return out << "Rs " << amount / 100 << '.' << (amount % 100 < 10 ? "0" : "")
                   << amount % 100;
    }
};

int main() {
    Money first(12, 75), second(3, 60);
    cout << "Sum: " << first + second << "\nDifference: " << first - second << '\n';
}
