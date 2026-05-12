/*
Program to demonstrate pthread_exit() and returning values from threads in C.
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : exit.c
*/

// Header files
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Worker thread function
void* worker(void* arg) {
    int x = *(int*)arg;

    int* result = malloc(sizeof(int));
    if (!result) pthread_exit(NULL);

    *result = x * 5;

    printf("Worker computed: %d\n", *result);

    pthread_exit(result);
}

int main() {
    pthread_t tid;
    int input = 7;

    pthread_create(&tid, NULL, worker, &input);

    void* ret;
    pthread_join(tid, &ret);

    if (ret != NULL) {
        int* value = (int*)ret;
        printf("Main received: %d\n", *value);
        free(value);
    } else {
        printf("Worker returned NULL\n");
    }

    return 0;
}