#!/usr/bin/env python3

import socket

#HOST = '127.0.0.1'  # The server's hostname or IP address
HOST = '128.59.15.41' # reykjavik
PORT = 65432        # The port used by the server

SECRET_TOKEN = "3rb8hwefoiv142892r39b8n0bew893448"

def send_results(result_string):
    # result_string = SECRET_TOKEN
    print("sending " + result_string)
    result_string += "\n"
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        b_results = result_string.encode('ascii') # Encode as bytes
        s.sendall(b_results)
        data = s.recv(1024)

    print('Received', repr(data))
