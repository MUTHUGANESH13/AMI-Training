/*
Program to show single thread returning a value to main thread using pthread_join() function.
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : sj.c
*/

// Header files
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Worker thread function
void* worker(void* arg) {
    // Cast the argument to an integer pointer and dereference it
    int n = *(int*)arg;

    // Perform some computation (for demonstration, we'll just double the input)
    int* result = malloc(sizeof(int));
    *result = n * 2;

    printf("Worker processed value\n");

    return result;
}

int main() {
    // Declare a thread ID and an input value for the worker thread
    pthread_t tid;
    int input = 10;

    pthread_create(&tid, NULL, worker, &input);

    void* ret;
    pthread_join(tid, &ret);

    int* value = (int*)ret;
    printf("Result from thread = %d\n", *value);

    free(value);

    return 0;
}