/*
Program to print numbers alternately using mutex
Author   : MUTHUGANESH S
Date     : 14/03/2026
Filename : alt.c
*/

// Include necessary headers
#include <stdio.h>
#include <pthread.h>

// Shared variable and mutex
int num = 1;
pthread_mutex_t lock;

// Function to print odd numbers
void* printOdd(void* arg) {
    while (num <= 20) {
        pthread_mutex_lock(&lock);

        if (num % 2 != 0) {
            printf("Odd Thread: %d\n", num);
            num++;
        }

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

// Function to print even numbers
void* printEven(void* arg) {
    while (num <= 20) {
        pthread_mutex_lock(&lock);

        if (num % 2 == 0) {
            printf("Even Thread: %d\n", num);
            num++;
        }

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, printOdd, NULL);
    pthread_create(&t2, NULL, printEven, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}