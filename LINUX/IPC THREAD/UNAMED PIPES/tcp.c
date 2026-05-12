/*
Program to demonstrate communication between two child processes using unnamed pipe
Author   : MUTHUGANESH S
Date     : 12/03/2026
Filename : tcp.c
*/

// Include necessary header files
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Main function
int main() {
    int fd[2];
    // Create two child processes
    pid_t c1, c2;
    char msg[] = "Message from Child 1";
    char buffer[100];

    // Create an unnamed pipe
    pipe(fd);

    // Fork the first child process
    c1 = fork();

    // Check if the first child process is created successfully
    if (c1 == 0) {
        close(fd[0]);
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
    } else {
        c2 = fork();

        if (c2 == 0) {
            close(fd[1]);
            read(fd[0], buffer, sizeof(buffer));
            printf("Child 2 received: %s\n", buffer);
            close(fd[0]);
        } else {
            close(fd[0]);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}