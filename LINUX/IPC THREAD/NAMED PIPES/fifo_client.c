/*
Program to demonstrate FIFO communication (Client)
Author   : MUTHUGANESH S
Date     : 13/03/2026
Filename : fifo_client.c
*/

//Header files
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char message[] = "Hello from client";

    //Open the FIFO for writing
    fd = open("myfifo", O_WRONLY);

    write(fd, message, sizeof(message));

    close(fd);

    return 0;
}