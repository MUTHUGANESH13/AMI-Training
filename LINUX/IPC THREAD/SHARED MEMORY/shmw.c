/*
Program to demonstrate shared memory (Writer)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : shmw.c
*/

//Header files
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid;
    char *str;

    key_t key = ftok("shmfile", 65);

    //Create shared memory segment
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    str = (char*) shmat(shmid, NULL, 0);

    printf("Write Data: ");
    fgets(str, 100, stdin);

    printf("Data written to memory\n");

    return 0;
}