/*
Program to implement execvp()
Author   : MUTHUGANESH S
Date     : 08/02/2026
Filename : exe.c
*/

//Header files
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};

    printf("Before execvp()\n");

    // This line executes ONLY if execvp() succeeds
    execvp("ls", args);

    // This line executes ONLY if execvp fails
    perror("execvp failed");
    return 1;
}