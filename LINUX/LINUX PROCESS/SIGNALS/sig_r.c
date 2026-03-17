/*
Program to send a signal to another and handle it
Author: MUTHUGANESH S
Date     : 09/03/2026
Filename : sig_r.c
*/

// Include necessary header files
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig) {
    printf("Received SIGUSR1 (signal %d)\n", sig);
}

int main() {
    signal(SIGUSR1, handle_sigusr1);

    printf("Receiver PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    while (1) {
        pause();  // wait for signal
    }

    return 0;
}