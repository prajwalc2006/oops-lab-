#include <iostream>
#include <numeric>
#include <stdexcept>
using namespace std;

class Fraction {
    long long numerator, denominator;
    void simplify() {
        if (!denominator) throw invalid_argument("Denominator cannot be zero.");
        if (denominator < 0) { numerator = -numerator; denominator = -denominator; }
        long long divisor = gcd(numerator < 0 ? -numerator : numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }
public:
    Fraction(long long n = 0, long long d = 1) : numerator(n), denominator(d) {
        simplify();
    }
    friend istream& operator>>(istream& in, Fraction& fraction) {
        long long n, d;
        char slash;
        if (in >> n >> slash >> d) {
            if (slash != '/') { in.setstate(ios::failbit); return in; }
            fraction = Fraction(n, d);
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Fraction& fraction) {
        return out << fraction.numerator << '/' << fraction.denominator;
    }
};

int main() {
    Fraction value;
    cout << "Enter a fraction (numerator/denominator): ";
    try {
        if (!(cin >> value)) return 1;
        cout << "Simplified: " << value << '\n';
    } catch (const invalid_argument& error) {
        cerr << error.what() << '\n';
        return 1;
    }
}
