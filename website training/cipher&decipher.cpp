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
        } else if (isspace(ch)) {
            decryptedMessage += ch; // Keep spaces unchanged
        }
    }

    return decryptedMessage;
}

// Function to encrypt a message using the substitution cipher
string encrypt(const string& message, const string& cipherAlphabet) {
    string encryptedMessage = "";

    // Mapping each letter from the plaintext to its corresponding letter in the cipher alphabet
    for (char ch : message) {
        if (isalpha(ch)) {
            char encryptedChar = islower(ch) ? tolower(cipherAlphabet[ch - 'a']) : toupper(cipherAlphabet[ch - 'A']);
            encryptedMessage += encryptedChar;
        } else if (isspace(ch)) {
            encryptedMessage += ch; // Keep spaces unchanged
        }
    }

    return encryptedMessage;
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

    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Encrypt a message" << endl;
    cout << "2. Decrypt a message" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        string plaintext;
        cout << "Enter the plaintext: ";
        cin.ignore(); // Clear input buffer
        getline(cin, plaintext);

        string encryptedMessage = encrypt(plaintext, cipherAlphabet);
        cout << "Encrypted message: " << encryptedMessage << endl;
    } else if (choice == 2) {
        string encryptedMessage;
        cout << "Enter the encrypted message: ";
        cin.ignore(); // Clear input buffer
        getline(cin, encryptedMessage);

        string decryptedMessage = decrypt(encryptedMessage, cipherAlphabet);
        cout << "Decrypted message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid choice. Please choose either 1 or 2." << endl;
        return 1; // Exit program with failure code
    }

    return 0;
}

