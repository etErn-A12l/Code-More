import os
from cryptography.fernet import Fernet

# pip install cryptography
from PIL import Image
import io


def encrypt_image(image_path, key):
    f = Fernet(key)
    with open(image_path, "rb") as file:
        image_data = file.read()
    encrypted_data = f.encrypt(image_data)
    return encrypted_data


def decrypt_image(encrypted_data, key):
    f = Fernet(key)
    decrypted_data = f.decrypt(encrypted_data)
    decrypted_image = Image.open(io.BytesIO(decrypted_data))
    return decrypted_image


def main():
    # Generate a random Fernet key
    key = Fernet.generate_key()

    image_path = "path/to/image.png"

    # Encrypt the image
    encrypted_data = encrypt_image(image_path, key)
    with open("encrypted_image.bin", "wb") as file:
        file.write(encrypted_data)

    # Decrypt the image
    with open("encrypted_image.bin", "rb") as file:
        encrypted_data = file.read()
    decrypted_image = decrypt_image(encrypted_data, key)
    decrypted_image.save("decrypted_image.png")


if __name__ == "__main__":
    main()
