/*
Program to open a file
Author   : MUTHUGANESH S
Date     : 01/02/2026
Filename : Open.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    
    int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);

    //O_CREAT → create file if not present
    //O_WRONLY → write only

    if(fd == -1) {
        perror("open");
        return 1;
    }

    printf("File created\n");
    close(fd);
}