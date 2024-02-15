#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <dirent.h>
#define MAX_BUFFER_SIZE 1024

void searchForFile(char* filePath, char* result) {
    FILE* file = fopen(filePath, "r");
    if (file != NULL) {
        fclose(file);
        strcat(result, "Yes, the file exists!");
    } else {
        strcat(result, "No, the file does not exist!");
    }
}

void searchInFile(const char* filePath, const char* searchString, char* result) {
    FILE* file = fopen(filePath, "r");
    if (file != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            if (strstr(buffer, searchString) != NULL) {
                strcat(result, filePath);
                strcat(result, "\n");
                break;
            }
        }
        fclose(file);
    } else {
        perror("Unable to open file");
    }
}

void searchInDirectory(const char* dirPath, const char* searchString, char* result) {
    DIR* directory = opendir(dirPath);
    if (directory == NULL) {
        perror("Unable to open directory");
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[PATH_MAX];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
            if (entry->d_type == DT_DIR) {
                searchInDirectory(fullPath, searchString, result);
            } else if (entry->d_type == DT_REG) {
                searchInFile(fullPath, searchString, result);
            }
        }
    }
    closedir(directory);
}

void searchForString(const char* searchString, char* result) {
    char currentPath[PATH_MAX];
    if (getcwd(currentPath, sizeof(currentPath)) == NULL) {
        perror("Unable to get current working directory");
        return;
    }
    searchInDirectory(currentPath, searchString, result);
}

void displayFileContent(char* filePath, char* result) {
    FILE* file = fopen(filePath, "r");
    if (file != NULL) {
        strcat(result, "File exists, content of file:-\n");
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            strcat(result, buffer);
        }
        fclose(file);
    } else {
        strcpy(result, "File does not exist\n");
    }
}

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind to a specific port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(7234);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 7234...\n");

    // Accept connections
    while (1) {

        int clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket == -1) {
            perror("Accept failed");
            continue;
        }

        // Receive client choice
        int choice;
        recv(clientSocket, &choice, sizeof(choice), 0);
        printf("Choice: %d\n", choice);

        char buffer[MAX_BUFFER_SIZE] = "";
        char result[MAX_BUFFER_SIZE] = "";

        switch (choice) {

            case 1:
                recv(clientSocket, buffer, sizeof(buffer), 0);
                searchForFile(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;

            case 2:
                recv(clientSocket, buffer, sizeof(buffer), 0);
                searchForString(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;

            case 3:
                recv(clientSocket, buffer, sizeof(buffer), 0);
                displayFileContent(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;

            case 4:
                close(clientSocket);
                close(serverSocket);
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice from client.\n");

        }
        close(clientSocket);
    }

    return 0;
}


