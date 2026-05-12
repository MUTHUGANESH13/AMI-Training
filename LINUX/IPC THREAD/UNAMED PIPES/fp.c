/*
Program to transfer file contents using unnamed pipe
Author   : MUTHUGANESH S
Date     : 12/03/2026
Filename : fp.c
*/


// Include necessary header files
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;
    char buffer[100];
    int n;

    pipe(fd);
    pid = fork();

    if (pid > 0) {
        int file = open("input.txt", O_RDONLY);

        close(fd[0]);

        while ((n = read(file, buffer, sizeof(buffer))) > 0) {
            write(fd[1], buffer, n);
        }

        close(file);
        close(fd[1]);
        wait(NULL);
    } else {
        int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        close(fd[1]);

        while ((n = read(fd[0], buffer, sizeof(buffer))) > 0) {
            write(file, buffer, n);
        }

        close(file);
        close(fd[0]);
    }

    return 0;
}