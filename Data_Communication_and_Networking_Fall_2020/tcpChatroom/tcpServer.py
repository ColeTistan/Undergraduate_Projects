# Cole Tistan 
# Data Communications and Networking
# Semester Project

import socket
import threading

# necessary variables needed for server
host = '127.0.0.1'
port = 55555
serverBind = (host, port)

serverSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

serverSock.bind(serverBind)
serverSock.listen()

# client threads with usernames will be stored in an array.
clients = []
usernames = []


# sends message to all current users in server
def broadcast(message):
	for client in clients:
		client.send(message)

def clientHandler(client):
	while True:
		try:
			message = client.recv(1024)
			broadcast(message)
		except:
			index = clients.index(client)
			clients.remove(client)
			client.close()
			username = usernames[index]
			usernames.remove(username)
			broadcast(f'{username} has left the chat'.encode('ascii'))
			break

def receive():
	while True:
		client, address = serverSock.accept()
		print(f'connected with {str(address)}')
		
		client.send('NICK'.encode('ascii'))
		username = client.recv(1024).decode('ascii')

		if username == 'admin':
			client.send('PASS'.encode('ascii'))
			password = client.recv(1024).decode('ascii')

			# if password != :


		usernames.append(username)
		clients.append(client)

		print(f'username of the client is {username}')
		broadcast(f'{username} joined the chat!'.encode('ascii'))
		client.send('Connected to the server!'.encode('ascii'))

		thread = threading.Thread(target=clientHandler, args=(client, ))
		thread.start()

print(f'Server listening...')
receive()