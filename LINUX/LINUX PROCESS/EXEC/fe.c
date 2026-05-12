/*
Program to implement fork() and execlp()
Author   : MUTHUGANESH S
Date     : 08/02/2026    
Filename : fe.c
*/

// Include necessary header files
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child: executing 'ls -a'\n");

        execlp("ls", "ls", "-a", NULL);

        // Executes only if execlp fails
        perror("execlp failed");
        return 1;
    }
    else {
        // Parent process
        wait(NULL);
        printf("Parent: child finished execution\n");
    }

    return 0;
}