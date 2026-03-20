/*
Program to demonstrate producer-consumer using condition variable
Author   : MUTHUGANESH S
Date     : 12/03/2026
Filename : pc.c
*/

// Include necessary headers
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Define constants for buffer size
#define SIZE 5

// Buffer and count
int buffer[SIZE];
int count = 0;

// Mutex and condition variable for synchronization
pthread_mutex_t mutex;
pthread_cond_t cond;

// Producer thread function
void* producer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock(&mutex);

        while (count == SIZE)
            pthread_cond_wait(&cond, &mutex);

        buffer[count++] = i;
        printf("Produced: %d\n", i);

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    return NULL;
}

// Consumer thread function
void* consumer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock(&mutex);

        while (count == 0)
            pthread_cond_wait(&cond, &mutex);

        int item = buffer[--count];
        printf("Consumed: %d\n", item);

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);

        sleep(2);
    }
    return NULL;
}


// Main function
int main() {
    pthread_t p, c;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}