#include <iostream>
#include <stdexcept>
using namespace std;

class Time {
    int hour, minute;
public:
    Time(int h, int m) : hour(h), minute(m) {
        if (h < 0 || h > 23 || m < 0 || m > 59)
            throw invalid_argument("Time must be between 00:00 and 23:59.");
    }
    friend Time laterOf(const Time& first, const Time& second);
    friend ostream& operator<<(ostream& out, const Time& time);
};

Time laterOf(const Time& first, const Time& second) {
    return first.hour * 60 + first.minute >= second.hour * 60 + second.minute
        ? first : second;
}
ostream& operator<<(ostream& out, const Time& time) {
    if (time.hour < 10) out << '0';
    out << time.hour << ':';
    if (time.minute < 10) out << '0';
    return out << time.minute;
}

int main() {
    cout << "Later time: " << laterOf(Time(9, 45), Time(14, 20)) << '\n';
}
