/*
Program to print odd and even numbers from 1 to 100 using mutex and condition variables.
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : oe.c
*/

// Include necessary headers
#include <stdio.h>
#include <pthread.h>

// Declare mutex and condition variable
pthread_mutex_t lock;
pthread_cond_t cond;

// Global variable to track turn
int turn = 1; // 1 = odd thread, 0 = even thread

// Function to print odd numbers
void* print_odd(void* arg) {
    for (int i = 1; i <= 100; i += 2) {
        pthread_mutex_lock(&lock);

        while (turn != 1)
            pthread_cond_wait(&cond, &lock);

        printf("%d ", i);

        turn = 0;
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

// Function to print even numbers
void* print_even(void* arg) {
    for (int i = 2; i <= 100; i += 2) {
        pthread_mutex_lock(&lock);

        while (turn != 0)
            pthread_cond_wait(&cond, &lock);

        printf("%d ", i);

        turn = 1;
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, print_odd, NULL);
    pthread_create(&t2, NULL, print_even, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}