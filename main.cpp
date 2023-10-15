#include <iostream>
#include <string>
using namespace std;

string encrypt(string rawText, int key) {
    string encryptedText;

    for (char ch : rawText) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            encryptedText += char(((ch - base + key) % 26) + base);
        } else {
            encryptedText += ch;  // Keep non-alphabetic characters unchanged
        }
    }

    return encryptedText;
}


int main() {
    return 0;
}
