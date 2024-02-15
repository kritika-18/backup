#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
 
#define MAX_BUFFER_SIZE 1024
 
// Debug log levels
#define FATAL_LOG(msg) printf("[FATAL] %s\n", msg)
#define INFO_LOG(msg) printf("[INFO] %s\n", msg)
#define WARNING_LOG(msg) printf("[WARNING] %s\n", msg)
#define DEBUG_LOG(msg) printf("[DEBUG] %s\n", msg)
 
int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        FATAL_LOG("Socket creation failed");
        exit(EXIT_FAILURE);
    }
 
    // Connect to the server
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP address
    serverAddr.sin_port = htons(7234);                     // Server port
 
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        FATAL_LOG("Connection failed");
        exit(EXIT_FAILURE);
    }
 
    int choice;
    char buffer[MAX_BUFFER_SIZE];
 
    while (1) {
 
        printf("Options:\n");
        printf("1. Search for a file\n");
        printf("2. Search for a string in the filesystem\n");
        printf("3. Display the content of a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
 
        scanf("%d", &choice);
 
        send(clientSocket, &choice, sizeof(choice), 0);
 
        switch (choice) {
            case 1: ;
                INFO_LOG("User selected option 1: Search for a file");
                int case0SubChoice = 0;
                printf("    1. Enter with path\n");
                printf("    2. Enter without path\n");
                scanf("%d", &case0SubChoice);
                char basePath[MAX_BUFFER_SIZE] = "";
                printf("Enter the required information: ");
                if (case0SubChoice == 2) {
                    strcat(basePath, "/home2/user31");
                }
                scanf("%s", buffer);
                strcat(basePath, buffer);
                send(clientSocket, basePath, sizeof(buffer), 0);
                recv(clientSocket, buffer, sizeof(buffer), 0);
                printf("Server response:\n%s\n", buffer);
                break;
            case 2:
                INFO_LOG("User selected option 2: Search for a string in the filesystem");
                printf("Enter the required information: ");
                getchar();
                scanf("%[^\n]s", buffer);
                send(clientSocket, buffer, sizeof(buffer), 0);
                recv(clientSocket, buffer, sizeof(buffer), 0);
                printf("Server response:\n%s\n", buffer);
                if (strcmp(buffer, "") == 0) {
                    printf("This string was not found in any file\n");
                    break;
                }
                int case2SubChoice = 0;
                printf("    1. View a file\n");
                printf("    2. Do not view file\n");
                printf("    Enter Choice: ");
                scanf("%d", &case2SubChoice);
                getchar();
                if (case2SubChoice == 1) {
                    printf("    Enter the path: ");
                    scanf("%[^\n]s", buffer);
                    send(clientSocket, buffer, sizeof(buffer), 0);
                    recv(clientSocket, buffer, sizeof(buffer), 0);
                    printf("Server response:\n%s\n", buffer);
                }
                break;
            case 3:
                INFO_LOG("User selected option 3: Display the content of a file");
                printf("Enter the required information: ");
                getchar();
                scanf("%[^\n]s", buffer);
                send(clientSocket, buffer, sizeof(buffer), 0);
                recv(clientSocket, buffer, sizeof(buffer), 0);
                printf("Server response:\n%s\n", buffer);
                break;
            case 4:
                INFO_LOG("User selected option 4: Exit");
                close(clientSocket);
                exit(EXIT_SUCCESS);
 
            default:
                WARNING_LOG("Invalid choice.\n");
        }
    }
 
    return 0;
}
