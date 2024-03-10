def build_cipher_alphabet(key):
    key = key.lower()  # Convert key to lowercase
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    cipher_alphabet = ''

    # Add unique letters from the key to the cipher alphabet
    for char in key:
        if char not in cipher_alphabet:
            cipher_alphabet += char

    # Add remaining letters from the alphabet to the cipher alphabet
    for char in alphabet:
        if char not in cipher_alphabet:
            cipher_alphabet += char

    return cipher_alphabet

def encrypt(message, key):
    cipher_alphabet = build_cipher_alphabet(key)
    message = message.lower()  # Convert message to lowercase
    encrypted_message = ''

    for char in message:
        if char.isalpha():
            index = ord(char) - ord('a')
            encrypted_message += cipher_alphabet[index]
        else:
            encrypted_message += char

    return encrypted_message

def decrypt(message, key):
    cipher_alphabet = build_cipher_alphabet(key)
    decrypted_message = ''

    for char in message:
        if char.isalpha():
            index = cipher_alphabet.index(char)
            decrypted_message += chr(ord('a') + index)
        else:
            decrypted_message += char

    return decrypted_message

# Get input from the user
key = input("Enter the key (5 unique letters): ")
message = input("Enter the message to encrypt: ")

# Encrypt the message
encrypted_message = encrypt(message, key)
print("Encrypted message:", encrypted_message)

# Decrypt the message
decrypted_message = decrypt(encrypted_message, key)
print("Decrypted message:", decrypted_message)
