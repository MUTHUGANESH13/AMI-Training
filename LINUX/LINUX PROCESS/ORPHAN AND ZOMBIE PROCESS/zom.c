/*
Program to demonstrate Zombie process creation in C.
Author   : MUTHUGANESH S
Date     : 09/03/2026
Filename : zom.c
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
        printf("Child exiting (PID=%d)\n", getpid());
        exit(99);
    }
    else {
        // Parent process
        printf("Parent sleeping (PID=%d)\n", getpid());
        sleep(10);  // Delay wait()

        // Uncomment to clean zombie:
        // wait(NULL);

        printf("Parent exiting\n");
    }

    return 0;
}