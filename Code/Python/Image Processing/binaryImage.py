from PIL import Image

# Load image and convert to grayscale
image = Image.open("tj.jpg").convert("L")

# Set a threshold value (128 is a common choice)
threshold = 128

# Apply binary threshold to create black and white image
bw_image = image.point(lambda x: 0 if x < threshold else 255)

# Get width and height
width, height = image.size

# Create a 2D array to store pixel values
pixels = [[0 for _ in range(width)] for __ in range(height)]

# Fill the 2D array with pixel values
for y in range(height):
    for x in range(width):
        pixels[y][x] = bw_image.getpixel((x, y))

print("Image\n\n")
for row in pixels:
    print(row)

# Create a new empty grayscale image with the same size
new_image = Image.new("L", (width, height))

# Set the pixel values of the new image using the 2D array
for y in range(height):
    for x in range(width):
        new_image.putpixel((x, y), pixels[y][x])

# Save the new image
new_image.save("new-tj.jpg")

# Show the new image
new_image.show()
