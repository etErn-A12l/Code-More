def str_to_bin_with_parity(string):
    # converting string into binary
    binary_string = ''.join(format(ord(i), '08b') for i in string)
    
    # calculating parity bit
    ones = binary_string.count('1')
    if ones % 2 == 0:
        parity_bit = '0'
    else:
        parity_bit = '1'
    
    # appending the parity bit to binary string
    data = binary_string + parity_bit
    
    return data

def check_parity(data):
    # extracting the parity bit
    parity_bit = data[-1:]
    # removing the parity bit from binary string
    binary_string = data[:-1]
    
    # checking for errors
    ones = binary_string.count('1')
    if ones % 2 == 0 and parity_bit == '0':
        print("Data received successfully!")
    elif ones % 2 != 0 and parity_bit == '1':
        print("Data received successfully!")
    else:
        print("Error occurred during transmission.")


st = input("Enter a string: ") 
data = str_to_bin_with_parity(st)
# print(data)
# print(type(data))
check_parity(data)