/*
Program to demonstrate FIFO communication (Server)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : fifo_server.c
*/

//Header files
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    //Create the FIFO (named pipe)
    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_RDONLY);

    read(fd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    close(fd);

    return 0;
}