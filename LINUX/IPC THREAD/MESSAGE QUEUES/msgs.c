/*
Program to demonstrate message queue (Sender)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : msgs.c
*/

// Include necessary header files
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Define the structure for the message buffer
struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int msgid;
    struct msgbuf message;

    key_t key = ftok("msgfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    message.mtype = 1;
    strcpy(message.mtext, "Hello from sender");

    msgsnd(msgid, &message, sizeof(message.mtext), 0);

    printf("Message sent\n");

    return 0;
}