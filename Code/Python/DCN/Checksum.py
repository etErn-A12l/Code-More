def bin2dec(b):

    b.reverse()
    d = 0
    for i in range(len(b)):
        d = d + b[i] * 2**i
    return d


def dec2bin(d, k):

    b = []
    for i in range(k):
        r = d % 2
        d //= 2
        b.append(r)
    b.reverse()
    return b


def packSend():

    data = [1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0]
    k = 4
    m = len(data) // k
    bd = []
    for i in range(m):
        p = data[k * i : (k * i + k)]
        dp = bin2dec(p)
        bd.append(dp)
    s = sum(bd)
    sbc = ~s + 1
    sb = dec2bin(sbc, k)
    packet = data.copy()
    print("Checksum = ", sb)
    for i in sb:
        packet.append(i)
    print("Original Data :", data)
    print("Packet sent :", packet)
    return packet


def packRecieve(data):

    k = 4
    m = len(data) // k
    bd = []
    for i in range(m):
        p = data[k * i : (k * i + k)]
        dp = bin2dec(p)
        bd.append(dp)
    s = sum(bd)
    print(dec2bin(s, k))
    if (dec2bin(s, k)) == [0, 0, 0, 0]:
        print("Error Free !")
    else:
        print("Error Detected !")


data = packSend()
packRecieve(data)
