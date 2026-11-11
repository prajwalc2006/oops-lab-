#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Logger {
public:
    virtual void write(const string& message) = 0;
    virtual ~Logger() = default;
};
class ConsoleLogger : public Logger {
public:
    void write(const string& message) override { cout << message << '\n'; }
};
class FileLogger : public Logger {
    ofstream output;
public:
    explicit FileLogger(const string& path) : output(path) {
        if (!output) throw runtime_error("Could not open log file.");
    }
    void write(const string& message) override { output << message << '\n'; }
};

int main() {
    try {
        vector<unique_ptr<Logger>> loggers;
        loggers.push_back(make_unique<ConsoleLogger>());
        loggers.push_back(make_unique<FileLogger>("diy8.log"));
        for (const auto& logger : loggers) logger->write("Application started.");
        cout << "A copy was also written to diy8.log.\n";
    } catch (const exception& error) {
        cerr << error.what() << '\n';
        return 1;
    }
}
