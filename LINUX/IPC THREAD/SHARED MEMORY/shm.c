/*
Program to demonstrate attach, detach, remove shared memory
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : shm.c
*/

//Header files
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    char *ptr;

    key_t key = ftok("shmfile", 90);

    // Create shared memory segment
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    ptr = (char*) shmat(shmid, NULL, 0);

    printf("Attached shared memory\n");

    sprintf(ptr, "Test Message");

    printf("Data: %s\n", ptr);

    shmdt(ptr);
    printf("Detached shared memory\n");

    shmctl(shmid, IPC_RMID, NULL);
    printf("Removed shared memory\n");

    return 0;
}