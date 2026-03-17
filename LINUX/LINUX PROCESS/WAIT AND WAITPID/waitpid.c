/*
Program to implement waitpid()
Author   : MUTHUGANESH S
Date     : 08/02/2026
Filename : waitpid.c
*/

// Include necessary header files
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;
    int status;

    pid1 = fork();

    if (pid1 == 0) {
        // First child
        sleep(2);
        printf("Child 1 done (PID=%d)\n", getpid());
        exit(21);
    }

    pid2 = fork();

    if (pid2 == 0) {
        // Second child
        sleep(1);
        printf("Child 2 done (PID=%d)\n", getpid());
        exit(42);
    }

    // Parent process
    printf("Parent waiting specifically for child PID %d\n", pid1);

    waitpid(pid1, &status, 0);

    if (WIFEXITED(status)) {
        printf("Parent: Child %d exited with status %d\n",
               pid1, WEXITSTATUS(status));
    }

    // Clean up remaining child
    wait(NULL);

    return 0;
}