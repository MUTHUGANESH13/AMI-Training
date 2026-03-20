/*
Program to demonstrate FIFO Client-Server (Client)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : cs_client.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;
    char request[] = "Hello Server";
    char response[100];

    fd1 = open("req_fifo", O_WRONLY);
    write(fd1, request, sizeof(request));

    fd2 = open("res_fifo", O_RDONLY);
    read(fd2, response, sizeof(response));

    printf("Server Response: %s\n", response);

    close(fd1);
    close(fd2);

    return 0;
}