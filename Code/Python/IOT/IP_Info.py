IP = input("\nEnter the IP address: ")

octets = IP.split(".")  # Splits the octets
# Converts the Decimal of first octet to 8 bit binary
binctet = "{0:b}".format(int(octets[0])).zfill(8)
i = 0
clss = ""
for j in range(5):
    if binctet[j] == "0":
        i = j
        clss = chr(65 + i)
        break

cls_s = 0
cls_e = 2**7  # 127
for j in range(i):
    cls_s += 2**7 / 2**j
    cls_e += 2**7 / 2 ** (j + 1)

cls_r = f"{int(cls_s)}" + ".0" * 3 + " - " + f"{int(cls_e-1)}" + ".255" * 3
c_hosts = 2 ** (32 - i - 1)
n_hosts = 2 ** (8 * (4 - i - 1))
n_id = ".".join(octets[: i + 1])
h_id = "x." * (i + 1) + ".".join(octets[i + 1 :])
net_r = f"{n_id}" + ".0" * (2 - i) + ".1" + " - " + f"{n_id}" + ".0" * (2 - i) + ".254"
n_id += ".0" * (3 - i)
n_mask = "255." * (i + 1) + "0." * (3 - i)
h_mask = "0." * (i + 1) + "255." * (3 - i)
p = 1 if i < 3 else 0

print()
print(f"{'Given IP Address ':<24}: {IP}")
print(f"{'Given IP Class ':<24}: Class {clss}")
print(f"{'Class Range ':<24}: " + f"{cls_r}" * p + "N/A" * (1 - p))
print(f"{'Possible Class Hosts ':<24}: " + f"{c_hosts}" * p + "N/A" * (1 - p))
print(f"{'Possible Network Hosts ':<24}: " + f"{n_hosts}" * p + "N/A" * (1 - p))
print(f"{'Network Mask ':<24}: " + f"{n_mask}" * p + "N/A" * (1 - p))
print(f"{'Host Mask ':<24}: " + f"{h_mask}" * p + "N/A" * (1 - p))
print(f"{'Network ID of Given IP ':<24}: " + f"{n_id}" * p + "N/A" * (1 - p))
print(f"{'Host ID of Given IP ':<24}: " + f"{h_id}" * p + "N/A" * (1 - p))
print(f"{'Network Range ':<24}: " + f"{net_r}" * p + "N/A" * (1 - p))
print()


'''

# Define IP Class related information in a dictionary
ip_info = {
    "A": {
        "mask": "255.0.0.0",
        "range": [".0.0.1", ".0.0.254"]
    },
    "B": {
        "mask": "255.255.0.0",
        "range": [".0.1", ".0.254"]
    },
    "C": {
        "mask": "255.255.255.0",
        "range": [".1", ".254"]
    }
}

IP_classes = ["A", "B", "C"]

IP = input("\nEnter the IP address: ")

# Splits the octets
octets = IP.split(".")

for octet in octets:
    if not int(octet) in range(256):
        print("\nINVALID IP Address !!\n")
        exit(1)

# Converts the Decimal of first octet to 8 bit binary
binctet = "{0:b}".format(int(octets[0])).zfill(8)

IP_class = ""

if binctet[0] == "0":
    IP_class = IP_classes[0]
elif binctet[0] == "1" and binctet[1] == "0":
    IP_class = IP_classes[1]
elif binctet[0] == "1" and binctet[1] == "1" and binctet[2] == "0":
    IP_class = IP_classes[2]

Net_Mask = ip_info[IP_class]["mask"]
NetIDoctet = IP_classes.index(IP_class) + 1

NetID = ".".join(octets[:NetIDoctet])
HostID = ".".join(octets[NetIDoctet:])
Ren_S = NetID + ip_info[IP_class]["range"][0]
Ren_E = NetID + ip_info[IP_class]["range"][-1]

print()
print(f"{'Given IP Address:':<24} {IP}")
print(f"{'Class of Given IP:':<24} Class {IP_class}")
print(f"{'Net Mask of Given IP:':<24} {Net_Mask}")
print(f"{'Network ID of Given IP:':<24} {NetID}")
print(f"{'Host ID of Given IP:':<24} {HostID}")
print(f"{'Range of IP Network:':<24} {Ren_S} - {Ren_E}")
print()

'''