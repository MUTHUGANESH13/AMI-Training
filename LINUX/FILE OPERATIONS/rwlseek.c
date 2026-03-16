/*
Program to read and write using lseek
Author   : MUTHUGANESH S    
Date     : 03/02/2026
Filename : rwlseek.c
*/

//Header files
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd;
    char buffer[50];

    fd = open("random.txt", O_RDWR | O_CREAT, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    strcpy(buffer, "HELLO");

    lseek(fd, 10, SEEK_SET);
    write(fd, buffer, strlen(buffer));

    lseek(fd, 30, SEEK_SET);
    write(fd, "LINUX", 5);

    lseek(fd, 10, SEEK_SET);
    read(fd, buffer, 5);
    buffer[5] = '\0';

    printf("Data at offset 10: %s\n", buffer);

    lseek(fd, 30, SEEK_SET);
    read(fd, buffer, 5);
    buffer[5] = '\0';

    printf("Data at offset 30: %s\n", buffer);

    close(fd);

    return 0;
}