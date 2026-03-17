/*
Program to print odd and even numbers from 1 to 100 using mutex.
Author   : MUTHUGANESH S
Date     : 11/03/2026
Filename : ooe.c
*/

// This program creates two threads: one for printing odd numbers and another for printing even numbers.
#include <stdio.h>
#include <pthread.h>

// Mutex to synchronize access to the shared variable 'turn'.
pthread_mutex_t lock;
int turn = 1;

// Function to print odd numbers from 1 to 100.
void* print_odd(void* arg) {
    for (int i = 1; i <= 100; i += 2) {
        while (1) {
            pthread_mutex_lock(&lock);

            if (turn == 1) {
                printf("%d ", i);
                turn = 0;
                pthread_mutex_unlock(&lock);
                break;
            }

            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}

// Function to print even numbers from 1 to 100.
void* print_even(void* arg) {
    for (int i = 2; i <= 100; i += 2) {
        while (1) {
            pthread_mutex_lock(&lock);

            if (turn == 0) {
                printf("%d ", i);
                turn = 1;
                pthread_mutex_unlock(&lock);
                break;
            }

            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, print_odd, NULL);
    pthread_create(&t2, NULL, print_even, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}