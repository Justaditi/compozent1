#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string caesarCipherEncrypt(string text, int shift) {
    string encryptedText = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encryptedText += char((c - base + shift) % 26 + base);
        } else {
            encryptedText += c;
        }
    }
    return encryptedText;
}

string caesarCipherDecrypt(string text, int shift) {
    return caesarCipherEncrypt(text, -shift);
}

string substitutionCipherEncrypt(string text, string key) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string encryptedText = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encryptedText += islower(c) ? key[c - 'a'] : toupper(key[c - 'A']);
        } else {
            encryptedText += c;
        }
    }
    return encryptedText;
}

string substitutionCipherDecrypt(string text, string key) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string decryptedKey = alphabet;
    for (size_t i = 0; i < key.length(); ++i) {
        decryptedKey[key[i] - 'a'] = alphabet[i];
        decryptedKey[toupper(key[i]) - 'A'] = toupper(alphabet[i]);
    }
    return substitutionCipherEncrypt(text, decryptedKey);
}

int main() {
    int choice;
    cout << "Choose an encryption method:" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. Substitution Cipher" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        int shift;
        cout << "Enter the shift value for Caesar Cipher: ";
        cin >> shift;
        cin.ignore();
        string message;
        cout << "Enter the message to encrypt: ";
        getline(cin, message);
        string encryptedMessage = caesarCipherEncrypt(message, shift);
        cout << "Encrypted message: " << encryptedMessage << endl;
        string decryptedMessage = caesarCipherDecrypt(encryptedMessage, shift);
        cout << "Decrypted message: " << decryptedMessage << endl;
    } else if (choice == 2) {
        string key;
        cout << "Enter the substitution key (26 letters without spaces): ";
        cin >> key;
        cin.ignore();
        string message;
        cout << "Enter the message to encrypt: ";
        getline(cin, message);
        string encryptedMessage = substitutionCipherEncrypt(message, key);
        cout << "Encrypted message: " << encryptedMessage << endl;
        string decryptedMessage = substitutionCipherDecrypt(encryptedMessage, key);
        cout << "Decrypted message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

