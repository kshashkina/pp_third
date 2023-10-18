#include <iostream>
#include <string>
using namespace std;

extern "C" {
__declspec(dllexport) string encrypt(string rawText, int key) {
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

__declspec(dllexport) string decrypt(string encryptedText, int key) {
    string decryptedText;
    int remainder = key % 26;

    for (char ch : encryptedText) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            decryptedText += char(((ch - base - remainder + 26) % 26) + base);
        } else {
            decryptedText += ch;  // Keep non-alphabetic characters unchanged
        }
    }

    return decryptedText;
}
}
