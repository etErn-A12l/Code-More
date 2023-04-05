from PIL import Image


def text_to_binary(text):
    return "".join(format(ord(char), "08b") for char in text)


def binary_to_text(binary_data):
    return "".join(
        chr(int(binary_data[i : i + 8], 2)) for i in range(0, len(binary_data), 8)
    )


def hide_message(image_path, message, output_path):
    message_length = len(message) * 8
    img = Image.open(image_path)
    width, height = img.size

    if message_length > (width * height):
        raise ValueError("Message too large for this image.")

    delimiter = "00110011" * 4
    message_binary = text_to_binary(message) + delimiter
    idx = 0

    for y in range(height):
        for x in range(width):
            pixel = list(img.getpixel((x, y)))

            for i in range(3):
                if idx < len(message_binary):
                    bit_value = int(pixel[i]) & 1

                    if bit_value != int(message_binary[idx]):
                        pixel[i] = pixel[i] ^ 1

                    idx += 1

            img.putpixel((x, y), tuple(pixel))

    img.save(output_path)


def extract_message(image_path):
    img = Image.open(image_path)
    width, height = img.size
    hidden_bits = []

    for y in range(height):
        for x in range(width):
            pixel = img.getpixel((x, y))

            for value in pixel:
                hidden_bits.append(str(value & 1))

    hidden_data = "".join(hidden_bits)
    delimiter = "00110011" * 4
    delimiter_index = hidden_data.find(delimiter)
    binary_data = hidden_data[:delimiter_index]

    return binary_to_text(binary_data)


def main():
    image_path = "rgb.jpg"
    output_path = "output_image.jpg"
    hidden_message = "This is a secret message."

    hide_message(image_path, hidden_message, output_path)
    extracted_message = extract_message(output_path)

    print("Extracted Message:", extracted_message)


if __name__ == "__main__":
    main()
