/*
Program for multiple clients to server (Server)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : mqs.c
*/

//Header files
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//Message buffer structure
struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int msgid;
    struct msgbuf message;

    //Generate unique key
    key_t key = ftok("msgfile", 75);

    //Create message queue and get its identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    while (1) {
        msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);
        printf("Received from client: %s\n", message.mtext);
    }

    return 0;
}