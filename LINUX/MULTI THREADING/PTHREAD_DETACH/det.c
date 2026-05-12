/*
Program to demonstrate the use of pthread_detach in C.
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : det.c
*/

//Header files
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Worker thread function
void* worker(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Worker running: %d\n", i);
        sleep(1);
    }
    printf("Worker finished\n");
    return NULL;
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, worker, NULL);

    pthread_detach(tid);

    printf("Main thread exiting immediately...\n");

    return 0;
}