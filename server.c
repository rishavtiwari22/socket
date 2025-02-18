#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8000
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 100

typedef struct {
    int socket;
    char username[BUFFER_SIZE];
} client_info;

client_info clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_handler(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytesRead;

    while ((bytesRead = read(client->socket, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s: %s", client->username, buffer);

        // Check if the message is a private message
        if (buffer[0] == '@') {
            char target_user[BUFFER_SIZE];
            char message[BUFFER_SIZE];
            sscanf(buffer, "@%s %[^\n]", target_user, message);

            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < client_count; i++) {
                if (strcmp(clients[i].username, target_user) == 0) {
                    char private_message[BUFFER_SIZE];
                    snprintf(private_message, BUFFER_SIZE, "[PM from %s]: %s\n", client->username, message);
                    send(clients[i].socket, private_message, strlen(private_message), 0);
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
        } else {
            // Broadcast the message to all clients
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < client_count; i++) {
                if (clients[i].socket != client->socket) {
                    send(clients[i].socket, buffer, strlen(buffer), 0);
                }
            }
            pthread_mutex_unlock(&clients_mutex);
        }
    }

    // Remove the client from the list
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket == client->socket) {
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addr_len = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            client_info *client = (client_info *)malloc(sizeof(client_info));
            client->socket = new_socket;
            read(client->socket, client->username, BUFFER_SIZE);
            client->username[strlen(client->username) - 1] = '\0'; // Remove newline
            clients[client_count++] = *client;

            pthread_t thread;
            pthread_create(&thread, NULL, client_handler, (void *)client);
            pthread_detach(thread);
        } else {
            close(new_socket);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(server_fd);
    return 0;
}