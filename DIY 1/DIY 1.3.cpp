#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string sentence, word;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    istringstream input(sentence);
    vector<string> words;
    while (input >> word) words.push_back(word);
    reverse(words.begin(), words.end());

    for (size_t i = 0; i < words.size(); ++i)
        cout << (i ? " " : "") << words[i];
    cout << '\n';
}
