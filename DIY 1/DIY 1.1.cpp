#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    int vowels = 0, consonants = 0;
    for (unsigned char ch : sentence) {
        if (!isalpha(ch)) continue;
        ch = static_cast<unsigned char>(tolower(ch));
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            ++vowels;
        else
            ++consonants;
    }

    cout << "Vowels: " << vowels << "\nConsonants: " << consonants << '\n';
}
