# @title Filling Rest with 0

import ipyplot
import numpy as np

SECRET = "I am Xron Trix"

def str_to_binary(string):
    binary_string = ""
    for char in string:
        # Get the ASCII value of the character
        ascii_value = ord(char)
        # Convert the ASCII value to binary and concatenate to the result
        binary_string += bin(ascii_value)[2:]  # [2:] removes the '0b' prefix from the binary representation
    return binary_string


px7 = pixel_slices[0]
px6 = pixel_slices[1]
px5 = pixel_slices[2]
px4 = pixel_slices[3]
px3 = pixel_slices[4]
px2 = pixel_slices[5]
px1 = pixel_slices[6]
px0 = pixel_slices[7]

bin_secret = str_to_binary(SECRET)

for j in range(len(bin_secret)):
    px0[j] = bin_secret[j]

new_px = []

for i in range(len(px6)):
    nw_str = px7[i] + px6[i] + px5[i] + px4[i] + px3[i] + px2[i] + px1[i] + px0[i]
    new_px.append(nw_str)


imgs = []
img = np.zeros((height, width))
imgs.append(img)
# for k in range(21):
#     img = np.zeros((height, width))
#     imgs.append(img)

a = 0
for i in range(height):
    for j in range(width):
        imgs[0][i][j] = int(new_px[a], 2)
        a += 1


ipyplot.plot_images(imgs, max_images=30, img_width=300, force_b64=True)
