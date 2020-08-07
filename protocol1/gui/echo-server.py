#!/usr/bin/env python3
import socket

#HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
HOST = ""           # If you pass an empty string, the server will accept all IPv4
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()


    logfile = open("logfile.csv", "a")
    with conn:
        print('Connected by', addr)
        recv_str = ""
        while True:
            data = conn.recv(1024)
            if not data:
                logfile.write(recv_str)
                break
            recv_str += data.decode('ascii')
            conn.sendall(data)

    logfile.close()
    print("logfile closed")

