/*
Program to implement wait()
Author   : MUTHUGANESH S
Date     : 08/02/2026
Filename : wait.c
*/

// Include necessary header files
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int i;
    pid_t pid;

    for (i = 0; i < 3; i++) {
        pid = fork();

        if (pid == 0) {
            // Child process
            printf("Child %d: PID = %d\n", i, getpid());
            exit(10 + i);  // distinct exit codes
        }
    }

    // Parent process
    int status;
    pid_t wpid;

    while ((wpid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            printf("Parent: Child with PID %d exited with status %d\n",
                   wpid, WEXITSTATUS(status));
        }
    }

    return 0;
}