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
