#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream input("in.txt");
    if (!input) {
        cerr << "Create in.txt, then run this program again.\n";
        return 1;
    }
    ofstream output("out.txt");
    if (!output) {
        cerr << "Could not create out.txt.\n";
        return 1;
    }

    string line;
    size_t lineNumber = 1;
    while (getline(input, line)) output << lineNumber++ << ": " << line << '\n';
    cout << "Wrote " << lineNumber - 1 << " numbered line(s) to out.txt.\n";
}
