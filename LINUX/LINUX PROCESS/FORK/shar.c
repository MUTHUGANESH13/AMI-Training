/*
Program to implement shared log file
Author   : MUTHUGANESH S
Date     : 08/02/2026
Filename : shar.c
*/

// Include necessary header files
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("shared.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd < 0) {
        printf("File open error\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        write(fd, "Child writing\n", 14);
    }
    else {
        // Parent process
        write(fd, "Parent writing\n", 15);
    }

    close(fd);
    return 0;
}