import random

# This function creates a hash value from the key to be used as a seed in generating the pn_sequence
def hash_key(key):
    return sum(ord(c) for c in key)


# This function generates a pseudo-random binary sequence of specified length using the provided seed value
def generate_pn_sequence(length, seed):
    random.seed(seed)
    pn_sequence = [random.randint(0, 1) for _ in range(length)]
    return pn_sequence


# This function encrypts the plaintext using the key provided and returns the ciphertext
def encrypt(plaintext, key):
    # Convert plaintext into binary string representation
    plaintext_bin = "".join(format(ord(c), "08b") for c in plaintext)
    # Convert key into binary string representation
    key_bin = "".join(format(ord(c), "08b") for c in key)

    # Create a seed value by hashing the key
    seed = hash_key(key)
    # Generate a pn_sequence using the seed value
    pn_sequence = generate_pn_sequence(len(plaintext_bin), seed)

    # XOR the plaintext binary values with the pn_sequence based on key bits
    ciphertext_bin = ""
    for i in range(len(plaintext_bin)):
        key_bit = int(key_bin[i % len(key_bin)])
        xor_result = int(plaintext_bin[i]) ^ (pn_sequence[i] if key_bit else 0)
        ciphertext_bin += str(xor_result)

    # Convert the binary ciphertext back into a string and return it
    ciphertext = ""
    for i in range(0, len(ciphertext_bin), 8):
        ciphertext += chr(int(ciphertext_bin[i : i + 8], 2))

    return ciphertext


# This function decrypts the ciphertext using the key provided and returns the original plaintext
def decrypt(ciphertext, key):
    # Convert ciphertext into binary string representation
    ciphertext_bin = "".join(format(ord(c), "08b") for c in ciphertext)
    # Convert key into binary string representation
    key_bin = "".join(format(ord(c), "08b") for c in key)

    # Create a seed value by hashing the key
    seed = hash_key(key)
    # Generate a pn_sequence using the seed value
    pn_sequence = generate_pn_sequence(len(ciphertext_bin), seed)

    # XOR the ciphertext binary values with the pn_sequence based on key bits to get plaintext binary values
    plaintext_bin = ""
    for i in range(len(ciphertext_bin)):
        key_bit = int(key_bin[i % len(key_bin)])
        xor_result = int(ciphertext_bin[i]) ^ (pn_sequence[i] if key_bit else 0)
        plaintext_bin += str(xor_result)

    # Convert the binary plaintext back into a string and return it
    plaintext = ""
    for i in range(0, len(plaintext_bin), 8):
        plaintext += chr(int(plaintext_bin[i : i + 8], 2))

    return plaintext


# Example usage of the encrypt and decrypt functions
plaintext = input("Plaintext: ")
key = input("Secret Key: ")

ciphertext = encrypt(plaintext, key)
print("Ciphertext:", ciphertext)

decrypted_plaintext = decrypt(ciphertext, key)
print("Decrypted plaintext:", decrypted_plaintext)
