/*
Program to allow only 3 processes in critical section
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : lim.c
*/

//Header files
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    //Create a named semaphore with an initial value of 3
    sem_t *sem;

    sem = sem_open("limitsem", O_CREAT, 0666, 3);

    printf("Process %d waiting...\n", getpid());

    sem_wait(sem);

    printf("Process %d entered\n", getpid());
    sleep(5);
    printf("Process %d leaving\n", getpid());

    sem_post(sem);

    sem_close(sem);

    return 0;
}