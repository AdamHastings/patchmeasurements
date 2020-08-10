#!/usr/bin/env python3

import socket

#HOST = 'www.cs.columbia.edu/~hastings/'  # The server's hostname or IP address
#HOST = 'tk0l.cs.columbia.edu'
#HOST = '127.0.0.1'
#HOST = '128.59.18.163' # tk0l
#HOST = '128.59.15.47' # seoul
HOST = '128.59.15.64' # reykjavik
PORT = 65432        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'Hello, world')
    data = s.recv(1024)

print('Received', repr(data))
