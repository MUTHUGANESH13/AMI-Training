/*
Program to implement fork()
Author   : MUTHUGANESH S
Date     : 08/02/2026
Filename : atomic.c
*/

// Include necessary header files
#include <stdio.h>
#include <unistd.h>

int main() {
    // Create a child process using fork()
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else {
        // Parent process
        printf("Parent Process:\n");
        printf("PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}