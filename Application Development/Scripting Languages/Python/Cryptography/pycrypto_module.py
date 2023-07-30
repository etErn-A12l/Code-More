import os
import hashlib
from Crypto.Cipher import AES

# pip install pycrypto
from Crypto import Random


def pad_key(key):
    return key + b"\0" * (32 - len(key))


def encrypt_file(file_path, key):
    key = pad_key(key)
    iv = Random.new().read(AES.block_size)
    cipher = AES.new(key, AES.MODE_CBC, iv)

    with open(file_path, "rb") as file:
        plaintext = file.read()

    padding_length = AES.block_size - len(plaintext) % AES.block_size
    plaintext += bytes([padding_length]) * padding_length

    ciphertext = iv + cipher.encrypt(plaintext)
    return ciphertext


def decrypt_file(encrypted_data, key):
    key = pad_key(key)
    iv = encrypted_data[: AES.block_size]
    cipher = AES.new(key, AES.MODE_CBC, iv)

    ciphertext = encrypted_data[AES.block_size :]
    plaintext = cipher.decrypt(ciphertext)

    padding_length = plaintext[-1]
    plaintext = plaintext[:-padding_length]

    return plaintext


def main():
    key = hashlib.sha256(b"your_password").digest()

    file_path = "path/to/file.txt"

    # Encrypt the file
    encrypted_data = encrypt_file(file_path, key)
    with open("encrypted_file.bin", "wb") as file:
        file.write(encrypted_data)

    # Decrypt the file
    with open("encrypted_file.bin", "rb") as file:
        encrypted_data = file.read()
    decrypted_data = decrypt_file(encrypted_data, key)

    with open("decrypted_file.txt", "wb") as file:
        file.write(decrypted_data)


if __name__ == "__main__":
    main()
