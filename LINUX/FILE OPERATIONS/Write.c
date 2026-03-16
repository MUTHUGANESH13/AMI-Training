/*
Program to illustarte write()
Author   : MUTHUGANESH S
Date     : 01/02/2026
Filename : Write.c
*/

//Header files
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd = open("hello.txt", O_CREAT | O_WRONLY, 0644);

    if(fd < 0) {
        perror("open");
        return 1;
    }

    char msg[] = "Hello, Linux!\n";

    if(write(fd, msg, sizeof(msg)) < 0) {
        perror("write");
    }

    close(fd);
}