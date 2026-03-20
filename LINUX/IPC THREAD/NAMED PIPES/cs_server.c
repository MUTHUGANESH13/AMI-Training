/*
Program to demonstrate FIFO Client-Server (Server)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : cs_server.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fd1, fd2;
    char request[100], response[100];

    mkfifo("req_fifo", 0666);
    mkfifo("res_fifo", 0666);

    fd1 = open("req_fifo", O_RDONLY);
    read(fd1, request, sizeof(request));

    printf("Client Request: %s\n", request);

    sprintf(response, "Processed: %s", request);

    fd2 = open("res_fifo", O_WRONLY);
    write(fd2, response, sizeof(response));

    close(fd1);
    close(fd2);

    return 0;
}