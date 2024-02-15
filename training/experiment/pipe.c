#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#define BUFFER_SIZE 100

int main() {
    int pipe_fd[2];
    pid_t child_pid;
    char buffer[BUFFER_SIZE];

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid > 0) {
        // Parent process

        // Close the write end of the pipe as it will not be used
        close(pipe_fd[1]);

        // Read from the pipe
        ssize_t bytesRead = read(pipe_fd[0], buffer, sizeof(buffer));
        if (bytesRead == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Print the read data
        printf("Parent Process: Received message from child: %s\n", buffer);

        // Close the read end of the pipe
        close(pipe_fd[0]);
    } else {
        // Child process

        // Close the read end of the pipe as it will not be used
        close(pipe_fd[0]);

        // Write to the pipe
        const char *message = "Hello from child!";
        ssize_t bytesWritten = write(pipe_fd[1], message, strlen(message));
        if (bytesWritten == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Close the write end of the pipe
        close(pipe_fd[1]);
    }

    return 0;
}

