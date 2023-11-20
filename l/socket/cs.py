import socket
import threading

def handle_client(client_socket):
    while True:
        data = client_socket.recv(1024)
        if not data:
            break
        print(f"Client: {data.decode()}")
        message = input("Server: ")
        client_socket.send(message.encode())
    client_socket.close()

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('', 12345))
    s.listen(5)
    print("Server is listening...")

    while True:
        client, addr = s.accept()
        print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")

        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

if __name__ == "__main__":
    main()
