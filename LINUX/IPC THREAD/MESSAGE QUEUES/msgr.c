/*
Program to demonstrate message queue (Receiver)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : msgr.c
*/

// Header files
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Structure for message queue
struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int msgid;
    struct msgbuf message;

    key_t key = ftok("msgfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);

    printf("Received: %s\n", message.mtext);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}