#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to generate the cipher alphabet based on the given key
string generateCipherAlphabet(const string& key) {
    string cipherAlphabet = key;

    // Adding remaining letters in order after the key letters
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (cipherAlphabet.find(ch) == string::npos) {
            cipherAlphabet += ch;
        }
    }

    return cipherAlphabet;
}

// Function to encrypt a message using the substitution cipher
string encryptMessage(const string& plaintext, const string& key) {
    string cipherAlphabet = generateCipherAlphabet(key);
    string encryptedMessage = "";

    // Mapping each letter from the plaintext to its corresponding letter in the cipher alphabet
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char encryptedChar = islower(ch) ? tolower(cipherAlphabet[ch - 'a']) : toupper(cipherAlphabet[ch - 'A']);
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += ch; // Keep non-alphabetic characters unchanged
        }
    }

    return encryptedMessage;
}

// Function to decrypt a message using the substitution cipher
string decryptMessage(const string& encryptedMessage, const string& key) {
    string cipherAlphabet = generateCipherAlphabet(key);
    string decryptedMessage = "";

    // Mapping each letter from the encrypted message to its corresponding letter in the original alphabet
    for (char ch : encryptedMessage) {
        if (isalpha(ch)) {
            size_t index = cipherAlphabet.find(tolower(ch));
            char decryptedChar = islower(ch) ? 'a' + index : 'A' + index;
            decryptedMessage += decryptedChar;
        } else {
            decryptedMessage += ch; // Keep non-alphabetic characters unchanged
        }
    }

    return decryptedMessage;
}

int main() {
    string key;
    bool validKey = false;
    
    while (!validKey) {
        cout << "Enter the key (5 unique letters): ";
        cin >> key;

        // Check if the key has exactly 5 unique letters
        if (key.length() != 5) {
            cout << "Key must have exactly 5 unique letters." << endl;
            continue;
        }
        
        unordered_map<char, bool> letterCounts;
        validKey = true;
        for (char ch : key) {
            if (!isalpha(ch)) {
                cout << "Key must contain only letters." << endl;
                validKey = false;
                break;
            }
            if (letterCounts[ch]) {
                cout << "Key must contain unique letters." << endl;
                validKey = false;
                break;
            }
            letterCounts[ch] = true;
        }
    }

    string plaintext;
    cout << "Enter the plaintext: ";
    cin.ignore(); // Clear input buffer
    getline(cin, plaintext);

    string encryptedMessage = encryptMessage(plaintext, key);
    cout << "Encrypted message: " << encryptedMessage << endl;

    string decryptedMessage = decryptMessage(encryptedMessage, key);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
