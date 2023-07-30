def encrypt_data(bin_data, bin_key):
    i = len(bin_key)-1
    temp = bin_data[0]
    bin_data = '1'+bin_data[1:]
    bin_data = bin_data+'0'*i
    result = bin_data[0:i]

    while (i < len(bin_data)):
        result = result+bin_data[i]

        if (len(result) == len(bin_key)):
            result = (bin((int(result, 2)) ^ (int(bin_key, 2))))[2:]

        i = i+1

    result = result.zfill(len(bin_key)-1)
    bin_data = bin_data[:len(bin_data)-len(bin_key)+1]+result
    bin_data = temp+bin_data[1:]

    return bin_data


def encode_data(data, key):
    bin_data = ""
    bin_key = ""

    for i in data:
        bin_value = (bin(ord(i)))[2:].zfill(8)
        bin_data = bin_data+bin_value

    for i in key:
        bin_value = (bin(ord(i)))[2:]
        bin_key = bin_key+bin_value

    return (encrypt_data(bin_data, bin_key))


data = input("Enter the message to be tansmitted : ")
key = input("Enter a secret code to hide the message : ")

print("Transmitted Data :", encode_data(data, key))







'''

The given code is used to encrypt a message (data) using a user-provided secret code (key). The encryption works by converting the input data and key into binary format and performing bitwise XOR operations. The output is an encrypted message in binary format.

Here's a detailed explanation of the functions and code:

1. **encrypt_data(bin_data, bin_key):** This function takes in two arguments - 'bin_data' which is the binary representation of the input data, and 'bin_key' which is the binary representation of the secret key. It proceeds with the following steps:

   - Store the length of the binary key minus 1 in 'i'
   - Temporarily store the first digit of 'bin_data' in 'temp' and replace it with '1'
   - Add 'i' number of zeroes at the end of 'bin_data' and extract its first 'i' digits into 'result'
   - Loop through 'bin_data', adding each element at position 'i' to 'result'
     - If the length of 'result' equals the length of 'bin_key', perform bitwise XOR operation on the integers represented by 'result' and 'bin_key', resulting in an updated 'result'
   - Pad 'result' with leading zeroes until it has the same length as 'bin_key' - 1
   - Update 'bin_data' by replacing its last (length of 'bin_key' - 1) digits with 'result' and restoring the original first digit that was stored in 'temp'

2. **encode_data(data, key):** This function converts the given data and key into their binary representations and calls the 'encrypt_data' function to encrypt the data:

   - Convert each character of 'data' into its binary equivalent by obtaining its unicode code point value and converting that into an 8-bit binary string, then concatenate those binary strings into 'bin_data'
   - Convert each character of 'key' into its binary equivalent and concatenate those binary strings into 'bin_key'
   - Call the 'encrypt_data' function with 'bin_data' and 'bin_key' as arguments and return the encrypted message

3. **Main code execution:**

   - Ask the user for a message (data) to be transmitted and store it in 'data'
   - Ask the user for a secret code (key) to hide the message and store it in 'key'
   - Call the 'encode_data' function with 'data' and 'key', and print the encrypted message, which is the transmitted data

In summary, the code takes a message and a secret key as inputs from the user, encrypts the message using a custom algorithm that works with the binary representations of the inputs, and prints the encrypted message.

'''