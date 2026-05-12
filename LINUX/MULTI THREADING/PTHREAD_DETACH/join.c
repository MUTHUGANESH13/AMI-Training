/*
Program to demonstrate the use of pthread_join in C.
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : join.c
*/

//Header files
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Number of threads to create
#define N 5

// Worker thread function
void* worker(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d started\n", id);

    sleep(2);

    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    pthread_t tid[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        ids[i] = i + 1;

        pthread_create(&tid[i], NULL, worker, &ids[i]);

        pthread_detach(tid[i]); // detach immediately
    }

    printf("Main thread will not join threads\n");

    // Keep process alive long enough
    sleep(3);

    printf("Main exiting\n");

    return 0;
}