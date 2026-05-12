/*
Program to send a signal to another process using kill() system call
Author: MUTHUGANESH S
Date     : 09/03/2026
Filename : sig_s.c
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("Enter receiver PID: ");
    scanf("%d", &pid);

    if (kill(pid, SIGUSR1) == 0) {
        printf("SIGUSR1 sent successfully\n");
    } else {
        perror("kill failed");
    }

    return 0;
}