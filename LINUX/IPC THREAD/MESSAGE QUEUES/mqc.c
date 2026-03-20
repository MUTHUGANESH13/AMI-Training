/*
Program for multiple clients to server (Client)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : mqc.c
*/

//Header files
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

//Message buffer structure
struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int msgid;
    struct msgbuf message;

    key_t key = ftok("msgfile", 75);

    msgid = msgget(key, 0666 | IPC_CREAT);

    message.mtype = 1;

    printf("Enter message: ");
    fgets(message.mtext, sizeof(message.mtext), stdin);

    msgsnd(msgid, &message, sizeof(message.mtext), 0);

    return 0;
}