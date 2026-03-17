/*
Process Signal Handling Example in C
Author   : MUTHUGANESH S
Date     : 09/03/2026
Filename : sig.c
*/

// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("\nCaught SIGINT (signal %d)\n", sig);
    printf("Exiting gracefully...\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("Press Ctrl+C to trigger SIGINT...\n");

    while (1) {
        sleep(1);
    }

    return 0;
}