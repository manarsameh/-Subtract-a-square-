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

// Function to encrypt a message using the substitution cipher
string encrypt(const string& message, const string& cipherAlphabet) {
    string encryptedMessage = "";

    // Mapping each letter from the plaintext to its corresponding letter in the cipher alphabet
    for (char ch : message) {
        if (isalpha(ch)) {
            char encryptedChar = islower(ch) ? tolower(cipherAlphabet[ch - 'a']) : toupper(cipherAlphabet[ch - 'A']);
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += ch; // Keep non-alphabetic characters unchanged
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
        bool validPlaintext = false;
        
        while (!validPlaintext) {
            cout << "Enter the plaintext: ";
            cin.ignore(); // Clear input buffer
            getline(cin, plaintext);

            validPlaintext = true;
            for (char ch : plaintext) {
                if (!isalpha(ch) && !isspace(ch)) {
                    cout << "Plaintext must contain only English letters and spaces." << endl;
                    validPlaintext = false;
                    break;
                }
            }
        }

        string encryptedMessage = encrypt(plaintext, cipherAlphabet);
        cout << "Encrypted message: " << encryptedMessage << endl;
    } else if (choice == 2) {
        string encryptedMessage;
        cout << "Enter the encrypted message: ";
        cin.ignore(); // Clear input buffer
        getline(cin, encryptedMessage);

        // Check if the encrypted message contains only English letters
        for (char ch : encryptedMessage) {
            if (!isalpha(ch)) {
                cout << "Invalid character detected. Please enter English letters only." << endl;
                return 1; // Exit program with failure code
            }
        }

        string decryptedMessage = decrypt(encryptedMessage, cipherAlphabet);
        cout << "Decrypted message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid choice. Please choose either 1 or 2." << endl;
        return 1; // Exit program with failure code
    }

    return 0;
}




