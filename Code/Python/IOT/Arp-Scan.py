
import random

# Generate a random IP address
def random_ip():
    ip = "192.168." + ".".join(str(random.randint(0, 255)) for _ in range(2))
    return ip

# Generate a random MAC address
def random_mac():
    mac = [0x00, 0x16, 0x3e,
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


my_ip = "192.168." + ".".join(str(random.randint(0, 255)) for _ in range(2))

for ip in dictionary:
    print(f"{ip :<15} : {dictionary[ip]}")

