import socket 
import sys 
import json 

print("This is CLIENT.")

#create socket
s = socket.socket() 
print("Socket successfully created")
#server ip address and port
server_ip = "192.168.1.121"
server_port = 8484

#connecting Client to Server
s.connect ((server_ip, server_port))
print("Got connection from Server")

#input bar from user
message = float(input("Enter pressure value in bar : ")) 

#convert string into JSON-formatted string
sendData3 = json.dumps(message)

#encode string into data and send it to Server
s.send(sendData3.encode())
print("Message sent to Server")

#receiving data from Server and decode into string
data2 = s.recv(1024).decode()
dataJ = data2
print("Server reply : " +dataJ)

#close socket
s.close()
