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

string decrypt(string encryptedText, int key) {
    string decryptedText;

    for (char ch : encryptedText) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            decryptedText += char(((ch - base - key + 26) % 26) + base);
        } else {
            decryptedText += ch;  // Keep non-alphabetic characters unchanged
        }
    }

    return decryptedText;
}

int main() {
    string rawText;
    int key;
    cout<< "Write your text"<< endl;
    cin >> rawText;
    cout << "Write your key"<<endl;
    cin>>key;

    string encryptedText = encrypt(rawText, key);
    string decryptedText = decrypt(encryptedText, key);

    cout << "Original Text: " << rawText << endl;
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}