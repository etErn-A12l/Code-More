import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind(("127.0.0.1", 2345))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"connected to this {addr}")
        while True:
            data = conn.recv(512)
            if not data:
                break
            print(f"client : {data} ")
            conn.sendall(data)
