#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8000
#define BUFFER_SIZE 1024


void *receive_messages(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytesRead;

    while ((bytesRead = read(sock, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer); 
    }

    printf("disconnected from Server.\n");
    return NULL;
}

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid addrass");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server on port %d\n", PORT);


    printf("enter your username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = '\0';
    send(sock, username, strlen(username) + 1, 0); 

    pthread_t thread;
    pthread_create(&thread, NULL, receive_messages, (void *)&sock);
    pthread_detach(thread);

    printf("Type massages (EX:, 'Hello' or '@username message'), or 'exit' to close:\n");
    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
        send(sock, buffer, strlen(buffer), 0);
    }

    close(sock);
    return 0;
}