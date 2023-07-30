
import random

# Generate a random IP address
def random_ip():
    ip = "192.168." + ".".join(str(random.randint(0, 255)) for _ in range(2))
    return ip

# Generate a random MAC address
def random_mac():
    mac = [0xa7, 0x16, 0x3e,
           random.randint(0x00, 0x7f),
           random.randint(0x00, 0xff),
           random.randint(0x00, 0xff)]
    mac_address = ":".join(map(lambda x: "%02x" % x, mac))
    return mac_address

# Generate a dictionary with random IP addresses and MAC addresses
dictionary = {}
count = 0
while count < 30:
    ip = random_ip()
    mac = random_mac()
    if ip and mac not in dictionary:
        dictionary[ip] = mac
        count += 1


my_ip = random.choice(list(dictionary.keys()))
my_mac = dictionary[my_ip]

print(dictionary)
print()
choice = input("ARP or R-ARP ? (1/2): ").lower()

if choice == "y":

    IP = input("Enter The IP Address to Find: ")

    print(f"\nSender:\n{'IP' :<4} {my_ip}\n{'MAC' :<4} {my_mac}")
    print(f"\nTarget:\n{'IP' :<4} {IP}\n{'MAC' :<4} " + ":".join("00" for _ in range(6)))
    if IP not in dictionary:
        print("\nReciever not FOUND !")
    else:
        print(f"\nReciever:\n{'IP' :<4} {IP}\n{'MAC' :<4} {dictionary[IP]}")

else:

    inverted_dict = {value: key for key, value in dictionary.items()}
    MAC = input("Enter The MAC Address to Find: ")

    print(f"\nSender:\n{'IP' :<4} {my_ip}\n{'MAC' :<4} {my_mac}")
    print(f"\nTarget:\n{'IP' :<4} " + ".".join("0" for _ in range(4)) + f"\n{'MAC' :<4} {MAC}")
    if MAC not in inverted_dict:
        print("\nReciever not FOUND !")
    else:
        print(f"\nReciever:\n{'IP' :<4} {inverted_dict[MAC]}\n{'MAC' :<4} {MAC}")



