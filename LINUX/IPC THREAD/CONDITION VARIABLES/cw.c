/*
Program to demonstrate waiting for a condition using condition variable
Author   : MUTHUGANESH S
Date     : 12/03/2026
Filename : cw.c
*/

// Include necessary headers
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Shared counter variable
int counter = 0;

// Mutex and condition variable for synchronization
pthread_mutex_t mutex;
pthread_cond_t cond;

// Incrementer thread function
void* incrementer(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);

        counter++;
        printf("Counter: %d\n", counter);

        if (counter == 10)
            pthread_cond_signal(&cond);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

// Waiter thread function
void* waiter(void* arg) {
    pthread_mutex_lock(&mutex);

    while (counter < 10)
        pthread_cond_wait(&cond, &mutex);

    printf("Counter reached 10. Proceeding...\n");

    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, incrementer, NULL);
    pthread_create(&t2, NULL, waiter, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}