# Client-side code to transfer files over local network
import socket

# define the IP address and port of the server to connect
IP_ADDRESS = "127.0.0.1"
PORT = 8080

# create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# connect to the server
sock.connect((IP_ADDRESS, PORT))

# define the file name and open it for reading
file_name = input("Enter file name to transfer: ")
file = open(file_name, 'rb')

# read the file and send it to the server
while True:
    chunk = file.read(4096)
    if not chunk:
        break
    sock.send(chunk)

# close the connection
sock.close()

print("File transfer successful!")