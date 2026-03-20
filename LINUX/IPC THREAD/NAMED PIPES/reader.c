/*
Program to read logs from FIFO
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : reader.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("logfifo", O_RDONLY);

    while (1) {
        read(fd, buffer, sizeof(buffer));
        printf("Received Log: %s", buffer);
    }

    close(fd);

    return 0;
}