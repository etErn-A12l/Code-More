IP_Classes = ["A", "B", "C"]
Net_Masks = ["255.0.0.0", "255.255.0.0", "255.255.255.0"]
range_SE = [".0.0.1", ".0.1", ".1", ".254", ".0.254", ".0.0.254"]

IP = input("\nEnter the IP address: ")
# IP = "221.255.255.255"

# Splits the octets
octets = IP.split(".")

for octet in octets:
    if int(octet) > 255:
        print("\nINVALID IP Address !!\n")
        exit(1)

# Converts the Decimal of first octet to 8 bit binary
binctet = "{0:b}".format(int(octets[0])).zfill(8)

IP_class = ""
Net_Mask = ""
NetIDoctet = 0

if binctet[0] == "0":
    IP_class = IP_Classes[0]
    Net_Mask = Net_Masks[0]
    NetIDoctet = 1
elif binctet[0] == "1" and binctet[1] == "0":
    IP_class = IP_Classes[1]
    Net_Mask = Net_Masks[1]
    NetIDoctet = 2
elif binctet[0] == "1" and binctet[1] == "1" and binctet[2] == "0":
    IP_class = IP_Classes[2]
    Net_Mask = Net_Masks[2]
    NetIDoctet = 3

NetID = ".".join(octets[:NetIDoctet])
HostID = ".".join(octets[NetIDoctet:])
Ren_S = NetID + range_SE[NetIDoctet - 1]
Ren_E = NetID + range_SE[len(range_SE) - NetIDoctet]

print()
print("{:<24} {}".format("Given IP Address: ", IP))
print("{:<24} Class {}".format("Class of Given IP: ", IP_class))
print("{:<24} {}".format("Net Mask of Given IP: ", Net_Mask))
print("{:<24} {}".format("Network ID of Given IP: ", NetID))
print("{:<24} {}".format("Host ID of Given IP: ", HostID))
print("{:<24} {} - {}".format("Range of IP Network: ", Ren_S, Ren_E))
print()
