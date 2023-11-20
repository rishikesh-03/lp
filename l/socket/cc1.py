import socket
import threading

def receive_messages(client_socket):
    while True:
        data = client_socket.recv(1024)
        if not data:
            break
        print(f"Server: {data.decode()}")

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    port = 12345
    s.connect(('127.0.0.1', port))

    receive_handler = threading.Thread(target=receive_messages, args=(s,))
    receive_handler.start()

    while True:
        message = input("Client: ")
        s.send(message.encode())

    s.close()

if __name__ == "__main__":
    main()
