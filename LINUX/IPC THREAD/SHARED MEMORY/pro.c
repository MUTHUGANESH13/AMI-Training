/*
Program for producer using shared memory + semaphore
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : pro.c
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int shmid;
    int *buffer;

    key_t key = ftok("shmfile", 75);
    shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);

    buffer = (int*) shmat(shmid, NULL, 0);

    sem_t *sem = sem_open("sem", O_CREAT, 0666, 1);

    for (int i = 1; i <= 5; i++) {
        sem_wait(sem);

        *buffer = i;
        printf("Produced: %d\n", i);

        sleep(1);

        sem_post(sem);
    }

    return 0;
}