/*
Program to demonstrate multi pthread_exit() and returning values from threads in C.
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : multiexit.c
*/

// Header files
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Number of threads to create
#define N 4

// Worker thread function
void* worker(void* arg) {
    int id = *(int*)arg;

    int* status = malloc(sizeof(int));
    if (!status) pthread_exit(NULL);

    *status = id * 10;

    printf("Thread %d exiting with %d\n", id, *status);

    pthread_exit(status);
}

int main() {
    pthread_t tid[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        ids[i] = i + 1;
        pthread_create(&tid[i], NULL, worker, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        void* ret;
        pthread_join(tid[i], &ret);

        if (ret != NULL) {
            int* value = (int*)ret;
            printf("Main collected from thread %d: %d\n", i + 1, *value);
            free(value);
        } else {
            printf("Thread %d returned NULL\n", i + 1);
        }
    }

    return 0;
}