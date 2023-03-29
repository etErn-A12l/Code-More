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
for i in range(len(dvdent) - len(dvsr)):

    r = xor(inDiv, chck(inDiv, dvsr))
    print(f"XOR ({inDiv} , {chck(inDiv,dvsr)})")
    r += dvdent[i + len(dvsr)]
    print(f"{r[:-1]}" + f" + {r[-1]}")
    inDiv = r[1:]

print(r[2:])

transmitter = o_data + r[2:]

print(f"Transmit it: {transmitter}")
