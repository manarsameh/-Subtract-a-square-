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

// Function to decrypt a message using the substitution cipher
string decrypt(const string& encryptedMessage, const string& cipherAlphabet) {
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

    string cipherAlphabet = generateCipherAlphabet(key);
    cout << "Cipher Alphabet: " << cipherAlphabet << endl;

    string message;
    cout << "Enter the message to encrypt: ";
    cin.ignore(); // Clear input buffer
    getline(cin, message);

    // Encryption
    string encryptedMessage = "";
    for (char ch : message) {
        if (isalpha(ch)) {
            size_t index = islower(ch) ? ch - 'a' : ch - 'A';
            encryptedMessage += cipherAlphabet[index];
        } else {
            encryptedMessage += ch; // Keep non-alphabetic characters unchanged
        }
    }

    cout << "Encrypted message: " << encryptedMessage << endl;

    // Decryption
    string decryptedMessage = decrypt(encryptedMessage, cipherAlphabet);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}

