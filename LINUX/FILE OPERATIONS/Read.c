/*
Program to read a file
Author   : MUTHUGANESH S
Date     : 01/02/2026
Filename : Read.c
*/

//Header files
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    char buffer[100];
    int fd = open("hello.txt", O_RDONLY);

    int n = read(fd, buffer, sizeof(buffer));

    write(1, buffer, n);

    close(fd);
}