def chck(a, b):
    return b if int(a) >= int(b) else "0" * len(dvsr)


def xor(a, b):
    r = ""
    for i in range(len(a)):
        s = int(a[i]) ^ int(b[i])
        r += str(s)
    return r


o_data = input("Enter original data in binary: ")
dvsr = input("Enter the divisor in binary: ")

crc_len = len(dvsr) - 1

dvdent = o_data + "0" * crc_len

print(f"{dvdent} / {dvsr}")

inDiv = dvdent[: len(dvsr)]

r = ""
i = len(dvsr) - 1
print(f"Initilly i = {i}")
while i <= len(dvdent):  # Until we reach the last bit of dvdent

    r = xor(inDiv, chck(inDiv, dvsr))  # bit wise xor operation
    print(f"XOR ({inDiv} , {chck(inDiv,dvsr)}) = ({r})")

    if i == len(dvdent) - 1:  # If last bit is already used, break
        break

    c = 0
    for k in range(len(r)):  # Checking how many bits are '0' from left to right
        if r[k] != "1":
            c += 1
        else:
            break

    r = r[c:]  # Discarding '0' bits

    for k in range(c + 1):
        r += dvdent[k + i]

    inDiv = r
    i += c

    print(f"Updated r = {r}, i = {i}")


# for i in range(len(dvdent) - len(dvsr)):

#     r = xor(inDiv, chck(inDiv, dvsr))
#     print(f"XOR ({inDiv} , {chck(inDiv,dvsr)})")
#     r += dvdent[i + len(dvsr)]
#     print(f"{r[:-1]}" + f" + {r[-1]}")
#     inDiv = r[1:]

print(f"Final r = {r[2:]}")

transmitter = o_data + r[2:]

print(f"Transmit it: {transmitter}")
