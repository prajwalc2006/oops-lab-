 #include <iostream>
#include <string>
using namespace std;

class Logger {
public:
    static Logger& get() {
        static Logger instance; // thread-safe since C++11
        return instance;
    }

    void log(const string& message) const {
        cout << "[LOG] " << message << endl;
    }

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

int main() {
    Logger::get().log("system up");
    Logger::get().log("same single instance");
    return 0;
}
