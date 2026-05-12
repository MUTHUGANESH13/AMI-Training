/*
Program to display message queue attributes
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : mqa.c
*/

//Header files
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int msgid;
    struct msqid_ds buf;

    //Generate unique key
    key_t key = ftok("msgfile", 90);

    msgid = msgget(key, 0666 | IPC_CREAT);

    msgctl(msgid, IPC_STAT, &buf);

    printf("Maximum bytes allowed: %ld\n", buf.msg_qbytes);
    printf("Current messages in queue: %ld\n", buf.msg_qnum);
    printf("Last send PID: %d\n", buf.msg_lspid);
    printf("Last receive PID: %d\n", buf.msg_lrpid);

    return 0;
}