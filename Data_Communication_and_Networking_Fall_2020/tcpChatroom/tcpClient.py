# Cole Tistan 
# Data Communications and Networking
# Semester Project

import socket
import threading

ipAddress = '127.0.0.1'
port = 55555
clientBind = (ipAddress, port)

# Allow client to enter a username
username = input('Choose a username: ')

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(clientBind)

def receive():
    while True:
        try:
            message = client.recv(1024).decode('ascii')
            if message == 'NICK':
                client.send(username.encode('ascii'))
            else:
                print(message)
        except:
            print('Oh no! It is not you. It is us.')
            client.close()
            break

def write():
    while True:
        message = f'{username}: {input("")}'
        client.send(message.encode('ascii'))

receive_thread = threading.Thread(target=receive)
receive_thread.start()

write_thread = threading.Thread(target=write)
write_thread.start()
