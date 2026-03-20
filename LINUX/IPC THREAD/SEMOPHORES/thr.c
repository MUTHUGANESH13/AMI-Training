/*
Program to demonstrate sem_wait and sem_post with threads
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : thr.c
*/

//  Header files
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Semaphore declaration
sem_t sem;

// Worker thread function
void* worker(void* arg) {
    int id = *(int*)arg;

    sem_wait(&sem);

    printf("Thread %d in critical section\n", id);
    sleep(2);
    printf("Thread %d leaving\n", id);

    sem_post(&sem);

    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    int id1 = 1, id2 = 2, id3 = 3;

    sem_init(&sem, 0, 1);

    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);
    pthread_create(&t3, NULL, worker, &id3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    sem_destroy(&sem);

    return 0;
}