import socket 
import sys 
import json 

print("This is CLIENT.")

#create socket
s = socket.socket() 
print("Socket successfully created")
#user input for server ip address and port
server_ip = "192.168.1.121"
server_port = 8888

#connecting Client to Server
s.connect ((server_ip, server_port))
print("Got connection from Server")

#receiving data from Server and decode into string
data2 = s.recv(1024).decode()
dataJ = data2
print("QOTD : " +dataJ)

#close socket
s.close()
