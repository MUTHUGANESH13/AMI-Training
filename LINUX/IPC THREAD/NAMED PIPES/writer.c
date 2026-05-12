/*
Program to write logs to FIFO
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : writer.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd;
    int i = 1;
    char log[100];

    mkfifo("logfifo", 0666);

    fd = open("logfifo", O_WRONLY);

    while (1) {
        sprintf(log, "Log message %d\n", i++);
        write(fd, log, sizeof(log));
        sleep(1);
    }

    close(fd);

    return 0;
}