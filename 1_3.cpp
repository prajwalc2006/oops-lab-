#include <iostream>
#include <string>

 #include <cctype>

using namespace std;

int main() {
    string S = "verification";

    cout << "First 4: " << S.substr(0, 4) << endl;
    cout << "From 4: " << S.substr(4) << endl;

    int cmp = S.compare("verify");
    cout << "Compare to verify: ";
    cout << (cmp < 0 ? "<" : (cmp > 0 ? ">" : "="));
    cout << endl;

    int freq[26] = {0};
    for (char ch : S) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char lower = tolower(static_cast<unsigned char>(ch));
            freq[lower - 'a']++;
        }
    }

    cout << "Letter counts:";
    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            cout << " " << char('a' + i) << ':' << freq[i];
        }
    }
    cout << endl;

    return 0;
}