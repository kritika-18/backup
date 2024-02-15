#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_STRING_LENGTH 100
#define MAX_FILENAME_LENGTH 255
#define MAX_CONTENT_LENGTH 1000

void searchAndListFiles(const char *dirPath, const char *searchString);

void displayFileContent(const char *filePath);

int main() {
    char searchString[MAX_STRING_LENGTH];

    printf("Enter the string to search: ");
    fgets(searchString, sizeof(searchString), stdin);
    searchString[strcspn(searchString, "\n")] = '\0';  // Remove newline character

    searchAndListFiles(".", searchString); // Start searching from the current directory

    return 0;
}
void searchAndListFiles(const char *dirPath, const char *searchString) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(dirPath)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char filePath[MAX_FILENAME_LENGTH];
        snprintf(filePath, sizeof(filePath),  dirPath, entry->d_name);

        if (entry->d_type == DT_DIR) {
            searchAndListFiles(filePath, searchString); // Recursive call for directories
        } else {
            FILE *file = fopen(filePath, "r");
            if (file == NULL) {
                perror("fopen");
                continue;
            }

            char line[MAX_CONTENT_LENGTH];
            while (fgets(line, sizeof(line), file) != NULL) {
                if (strstr(line, searchString) != NULL) {
                    printf("Found in file: %s\n", filePath);
                    displayFileContent(filePath);
                    break;
                }
            }

            fclose(file);
        }
    }

    closedir(dir); // Close the directory handle
}


void displayFileContent(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    printf("File content:\n");
    char line[MAX_CONTENT_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

