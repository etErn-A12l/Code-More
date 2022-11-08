import socket

HOST = "127.0.0.1"

PORT = 2345

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect ( (HOST, PORT) )
    s.sendall(b"hello baby")
    data = s.recv(512)
    print(f"{data} sent")
