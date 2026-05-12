/*
Program to demonstrate thread pool using condition variable
Author   : MUTHUGANESH S
Date     : 12/03/2026
Filename : tp.c
*/

// Include necessary headers
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//  Define constants for the number of threads and tasks
#define THREADS 3
#define TASKS 5

//  Task queue and count
int task_queue[TASKS];
int task_count = 0;

//  Mutex and condition variable for synchronization
pthread_mutex_t mutex;
pthread_cond_t cond;

//  Worker thread function
void* worker(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (task_count == 0)
            pthread_cond_wait(&cond, &mutex);

        int task = task_queue[--task_count];
        printf("Thread %ld processing task %d\n", (long)arg, task);

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t workers[THREADS];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (long i = 0; i < THREADS; i++)
        pthread_create(&workers[i], NULL, worker, (void*)i);

    for (int i = 1; i <= TASKS; i++) {
        pthread_mutex_lock(&mutex);

        task_queue[task_count++] = i;
        printf("Added task %d\n", i);

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    sleep(5);
    return 0;
}