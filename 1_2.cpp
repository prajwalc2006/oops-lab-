#include <iostream>
#include <String>
using namespace std;
int main() {
    cout << "Enter a word: ";
    string s;
    cin >> s;
    cout << "Length: " << s.length() << endl;
    cout << "Uppercase: ";
    for (char c : s) {
        cout << static_cast<char>(toupper(static_cast<unsigned char>(c)));
    }
    cout << endl;
    bool palindrome = true;
    for (size_t i = 0, j = s.length() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            palindrome = false;
            break;
        }
    }
    cout << s << (palindrome ? " is a palindrome\n" : " is not a palindrome\n");

    size_t pos = s.find("an");
    if (pos != string::npos) {
        cout << "'an' found at index " << pos << endl;
    } else {
        cout << "'an' not found" << endl;
    }

    return 0;
}