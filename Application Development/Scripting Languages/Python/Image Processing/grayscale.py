from PIL import Image

# Load image and convert to grayscale
image = Image.open("abcd.jpg").convert("L")

# Get width and height
width, height = image.size

# Create a 2D array to store pixel values
pixels = [[0 for _ in range(width)] for __ in range(height)]

# Fill the 2D array with pixel values
for y in range(height):
    for x in range(width):
        pixels[y][x] = image.getpixel((x, y))

print("Image\n\n")
for row in pixels:
    print(row)

# Create a new empty grayscale image with the same size
new_image = Image.new("RGB", (width, height))

# Set the pixel values of the new image using the 2D array
for y in range(height):
    for x in range(width):
        new_image.putpixel((x, y), pixels[y][x])

# Save the new image
new_image.save("new-grayscale-tj.jpg")

# Show the new image
new_image.show()

'''
pixels[y][x] = 170

R   G B

170 0 0 

'''