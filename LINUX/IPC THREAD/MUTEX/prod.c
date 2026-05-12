/*
Program to demonstrate producer-consumer using mutex
Author   : MUTHUGANESH S
Date     : 14/03/2026
Filename : prod.c
*/

// Include necessary headers
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Buffer size and shared variables
#define SIZE 5

// Shared buffer and count of items in the buffer
int buffer[SIZE];
int count = 0;

// Mutex lock for synchronizing access to the buffer
pthread_mutex_t lock;

// Producer thread function
void* producer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock(&lock);

        if (count < SIZE) {
            buffer[count++] = i;
            printf("Produced: %d\n", i);
        }

        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

// Consumer thread function
void* consumer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock(&lock);

        if (count > 0) {
            int item = buffer[--count];
            printf("Consumed: %d\n", item);
        }

        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}