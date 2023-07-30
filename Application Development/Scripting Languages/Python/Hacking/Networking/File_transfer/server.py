import socket
 
# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
 
# Port and address to bind to  
host = socket.gethostname()
port = 8080
 
# Bind to the port 
s.bind((host, port)) 
 
# Wait for a connection
s.listen(5) 
 
# Wait for connection
conn, addr = s.accept() 
print("Connection successful") 
 
# Receive the filename
filename = conn.recv(1024).decode()
 
# Open the file
f = open(filename, 'rb')
 
# Read bytes content and store it in file data
l = f.read(1024)
 
# Send the file data 
while(l):
    conn.send(l)
    l = f.read(1024)
f.close()
 
# Close the connection
conn.close()
