#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string first, second;
    cout << "Enter two words: ";
    if (!(cin >> first >> second)) return 1;

    auto normalize = [](string word) {
        word.erase(remove_if(word.begin(), word.end(), [](unsigned char ch) {
            return !isalpha(ch);
        }), word.end());
        transform(word.begin(), word.end(), word.begin(), [](unsigned char ch) {
            return static_cast<char>(tolower(ch));
        });
        sort(word.begin(), word.end());
        return word;
    };

    cout << (normalize(first) == normalize(second) ? "Anagrams\n" : "Not anagrams\n");
}
