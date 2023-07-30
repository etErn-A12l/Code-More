from PIL import Image


def xor_image(image_path, key):
    image = Image.open(image_path)
    width, height = image.size
    encrypted_image = Image.new("RGB", (width, height))

    for y in range(height):
        for x in range(width):
            pixel = image.getpixel((x, y))
            new_pixel = tuple([value ^ key for value in pixel])
            encrypted_image.putpixel((x, y), new_pixel)

    return encrypted_image


def main():
    image_path = "rgb.jpg"
    key = 132
    encrypted_image = xor_image(image_path, key)
    encrypted_image.save("encrypted_image.jpg")

# Call the function again for encrypted image to decrypt

if __name__ == "__main__":
    main()
