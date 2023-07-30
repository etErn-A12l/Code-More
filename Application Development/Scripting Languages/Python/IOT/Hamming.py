import math

def calculate_parity_bits(data):
    # Find the number of parity bits required to cover all data bits
    n = len(data)
    p = 0
    while 2 ** p < n + p + 1:
        p += 1

    # Initialize the parity bits with value 0
    parity_bits = [0] * p

    # Calculate the parity bits
    for i in range(p):
        for j in range(1, n + 1):
            if (j >> i) & 1 == 1:
                parity_bits[i] ^= data[j - 1]

    return parity_bits

def hamming_encode(data):
    # Calculate the number of parity bits and their values
    parity_bits = calculate_parity_bits(data)

    # Build the encoded message by inserting the parity bits into the correct positions
    encoded = []
    p = 0
    for i in range(1, len(data) + len(parity_bits) + 1):
        if i == 2 ** p:
            encoded.append(parity_bits[p])
            p += 1
        else:
            encoded.append(data.pop(0))

    return encoded

def hamming_decode(encoded):
    # Calculate the number of parity bits
    p = int(math.log(len(encoded), 2))

    # Initialize the error bit and syndrome with value 0
    error_bit = 0
    syndrome = [0] * p

    # Calculate the syndrome and the position of the error bit
    for i in range(p):
        for j in range(1, len(encoded) + 1):
            if (j >> i) & 1 == 1:
                syndrome[i] ^= encoded[j - 1]
        error_bit += syndrome[i] * (2 ** i)

    # Correct the error bit
    if error_bit != 0:
        encoded[error_bit - 1] ^= 1

    # Remove the parity bits and return the decoded message
    decoded = []
    p = 0
    for i in range(1, len(encoded) + 1):
        if i == 2 ** p:
            p += 1
        else:
            decoded.append(encoded[i - 1])

    return decoded

# Example usage
data = [1, 0, 1, 0]
encoded = hamming_encode(data)
print("Encoded message:", encoded)
decoded = hamming_decode(encoded)
print("Decoded message:", decoded)
