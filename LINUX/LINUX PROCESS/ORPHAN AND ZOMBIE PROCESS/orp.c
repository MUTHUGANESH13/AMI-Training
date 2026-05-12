/*
Program to demonstrate orphan process creation in C.
Author   : MUTHUGANESH S
Date     : 09/03/2026
Filename : orp.c
*/

// Include necessary header files
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        sleep(3);  // ensure parent exits first

        printf("Child: PID = %d\n", getpid());
        printf("Child: New Parent PID = %d\n", getppid());

        // Infinite loop to observe via ps
        while (1) {
            sleep(1);
        }
    }
    else {
        // Parent process
        printf("Parent: PID = %d\n", getpid());
        printf("Parent exiting...\n");
        exit(0);
    }

    return 0;
}