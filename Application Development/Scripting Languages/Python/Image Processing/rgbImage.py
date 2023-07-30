from PIL import Image

# Load image (assuming it's already in RGB format)
image = Image.open("tj.jpg")

# Get width and height
width, height = image.size

# Create a 3D array to store pixel values for each channel (R, G, B)
pixels = [[[0, 0, 0] for _ in range(width)] for __ in range(height)]

# Fill the 3D array with pixel values
for y in range(height):
    for x in range(width):
        pixels[y][x] = image.getpixel((x, y))

# Create a new empty RGB image with the same size
new_image = Image.new("RGB", (width, height))

# Set the pixel values of the new image using the 3D array
for y in range(height):
    for x in range(width):
        new_image.putpixel((x, y), tuple(pixels[y][x]))

# Save the new image
new_image.save("rgb.jpg")

# Show the new image
new_image.show()
