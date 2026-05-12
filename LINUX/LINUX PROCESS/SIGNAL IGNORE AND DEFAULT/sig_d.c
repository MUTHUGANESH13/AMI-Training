/*
Program to set default action for SIGTERM signal
Author   : MUTHUGANESH S
Date     : 10/03/2026   
Filename : sig_d.c
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("PID: %d\n", getpid());

    // Set SIGTERM to default action
    signal(SIGTERM, SIG_DFL);

    printf("Sending SIGTERM to self...\n");

    sleep(2);  // delay for observation

    kill(getpid(), SIGTERM);

    // This line will NOT execute if default action occurs
    printf("This line should not be printed\n");

    return 0;
}