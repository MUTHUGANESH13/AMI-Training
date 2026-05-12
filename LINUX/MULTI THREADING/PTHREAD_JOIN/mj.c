/*
Program to demonstrate multi join.
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : mj.c
*/

// Header files
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Number of threads to create
#define N 5

// Worker thread function
void* worker(void* arg) {
    int id = *(int*)arg;

    int* result = malloc(sizeof(int));
    *result = id * id;  // example computation

    printf("Thread %d computed %d\n", id, *result);

    return result;
}

int main() {
    // Array to hold thread IDs and their corresponding arguments
    pthread_t tid[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        ids[i] = i + 1;
        pthread_create(&tid[i], NULL, worker, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        void* ret;
        pthread_join(tid[i], &ret);

        int* value = (int*)ret;
        printf("Joined thread %d, result = %d\n", i + 1, *value);

        free(value); // critical to avoid memory leak
    }

    return 0;
}