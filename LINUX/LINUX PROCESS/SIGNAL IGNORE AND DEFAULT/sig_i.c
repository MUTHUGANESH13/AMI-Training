/*
Program to ignore SIGINT signalprocess
Author   : MUTHUGANESH S
Date     : 10/03/2026
Filename : sig_i.c
*/

// Include necessary header files
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Ignore SIGINT
    signal(SIGINT, SIG_IGN);

    printf("SIGINT is ignored. Press Ctrl+C...\n");

    while (1) {
        printf("Running...\n");
        sleep(2);
    }

    return 0;
}