/*
Program to demonstrate shared memory (Reader)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : shmr.c
*/

//Header files
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    char *str;

    //Generate unique key
    key_t key = ftok("shmfile", 65);

    //Create shared memory segment
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    str = (char*) shmat(shmid, NULL, 0);

    printf("Data read from memory: %s\n", str);

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}