def check_error(bin_data, bin_key):
    i = len(bin_key)-1
    bin_data = '1'+bin_data[1:]
    result = bin_data[0:i]

    while (i < len(bin_data)):
        result = result+bin_data[i]

        if (len(result) == len(bin_key)):
            result = (bin((int(result, 2)) ^ (int(bin_key, 2))))[2:]

        i = i+1

    if (int(result, 2) == 0):
        return 1

    else:
        return 0


def decode_data(data):
    original_data = ""

    for i in range(0, len(data), 8):
        ascii_value = int(data[i:(i+8)], 2)
        original_data = original_data+chr(ascii_value)

    return original_data


data = input("Enter the data received : ")
key = input("Enter the secret code : ")
bin_key = ""

for i in key:
    bin_value = (bin(ord(i)))[2:]
    bin_key = bin_key+bin_value

if (check_error(data, bin_key)):
    print("Message :", decode_data(data[:len(data)-len(bin_key)+1]))

else:
    print("! Data Corrupted !")