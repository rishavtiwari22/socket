#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);
        if (strncmp(buffer, "exit", 4) == 0) break;

        memset(buffer, 0, BUFFER_SIZE);
        int bytesRead = read(sock, buffer, BUFFER_SIZE);
        if (bytesRead > 0) {
            printf("Server: %s", buffer);
            if (strncmp(buffer, "exit", 4) == 0) break;
        } else if (bytesRead == 0) {
            printf("Connection closed by server\n");
            break;
        } else {
            perror("read error");
            break;
        }
    }

    close(sock);
    return 0;
}