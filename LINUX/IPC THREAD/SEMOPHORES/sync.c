/*
Program to synchronize shared resource using POSIX semaphore
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : sync.c
*/


//Header files
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    sem_t *sem;

    // Create or open a named semaphore
    sem = sem_open("mysem", O_CREAT, 0666, 1);

    printf("Waiting to enter critical section...\n");

    sem_wait(sem);

    printf("Entered critical section\n");
    sleep(3);
    printf("Exiting critical section\n");

    sem_post(sem);

    sem_close(sem);

    return 0;
}