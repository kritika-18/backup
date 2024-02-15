#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <dirent.h>
 
#define MAX_BUFFER_SIZE 1024
 
// Debug log levels
#define FATAL_LOG(msg) printf("[FATAL] %s\n", msg)
#define INFO_LOG(msg) printf("[INFO] %s\n", msg)
#define WARNING_LOG(msg) printf("[WARNING] %s\n", msg)
#define DEBUG_LOG(msg) printf("[DEBUG] %s\n", msg)
 
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
                DEBUG_LOG("Found matching string in file");
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
        if (entry->d_name[0] != '.' && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[PATH_MAX];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
            if (entry->d_type == DT_DIR) {
                if (strcmp(entry->d_name, "/") == 0 || strcmp(entry->d_name, "/proc") == 0 ||
                    strcmp(entry->d_name, "/sys") == 0 || strcmp(entry->d_name, "/dev") == 0)
                    continue;
                DEBUG_LOG("Searching directory recursively");
                searchInDirectory(fullPath, searchString, result);
            } else if (entry->d_type == DT_REG) {
                DEBUG_LOG("Searching file for string");
                searchInFile(fullPath, searchString, result);
            }
        }
    }
    closedir(directory);
}
 
void searchForString(const char* searchString, char* result) {
    DEBUG_LOG("Initiating search for string");
    searchInDirectory("/home2/user31", searchString, result);
}
 
void displayFileContent(char* filePath, char* result) {
    FILE* file = fopen(filePath, "r");
    if (file != NULL) {
        DEBUG_LOG("Displaying file content");
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
        FATAL_LOG("Socket creation failed");
        exit(EXIT_FAILURE);
    }
 
    // Bind to a specific port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(7234);
 
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        FATAL_LOG("Bind failed");
        exit(EXIT_FAILURE);
    }
 
    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        FATAL_LOG("Listen failed");
        exit(EXIT_FAILURE);
    }
 
    INFO_LOG("Server listening on port 7234...");
 
    int clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == -1) {
        perror("Accept failed");
    }
 
    // Accept connections
    while (1) {
 
        // Receive client choice
        int choice;
        recv(clientSocket, &choice, sizeof(choice), 0);
        printf("Choice: %d\n", choice);
 
        char buffer[MAX_BUFFER_SIZE] = "";
        char result[MAX_BUFFER_SIZE] = "";
 
        switch (choice) {
 
            case 1:
                INFO_LOG("Client requested file search");
                recv(clientSocket, buffer, sizeof(buffer), 0);
                searchForFile(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;
 
            case 2:
                INFO_LOG("Client requested string search");
                recv(clientSocket, buffer, sizeof(buffer), 0);
                searchForString(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                strcpy(result, "");
                recv(clientSocket, buffer, sizeof(buffer), 0);
                displayFileContent(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;
 
            case 3:
                INFO_LOG("Client requested file content display");
                recv(clientSocket, buffer, sizeof(buffer), 0);
                displayFileContent(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;
 
            case 4:
                INFO_LOG("Client requested to exit");
                close(clientSocket);
                close(serverSocket);
                exit(EXIT_SUCCESS);
 
            default:
                WARNING_LOG("Invalid choice from client.");
        }
    }
 
    close(clientSocket);
    return 0;
}
