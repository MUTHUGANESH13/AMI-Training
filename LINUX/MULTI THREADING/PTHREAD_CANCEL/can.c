/*
Program to demonstrate thread cancellation
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : can.c
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* worker(void* arg) {
    while (1) {
        printf("Worker thread running...\n");
        sleep(1); // cancellation point
    }
    return NULL;
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, worker, NULL);

    sleep(3); // let thread run

    printf("Main thread: Cancelling worker...\n");
    pthread_cancel(tid);

    void* status;
    pthread_join(tid, &status);

    if (status == PTHREAD_CANCELED)
        printf("Worker thread was cancelled successfully.\n");
    else
        printf("Worker thread exited normally.\n");

    return 0;
}